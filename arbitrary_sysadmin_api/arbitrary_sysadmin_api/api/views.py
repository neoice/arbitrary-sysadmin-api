# models
from models import Command

# django
from django.shortcuts import render_to_response, HttpResponse, get_object_or_404
#from django.contrib.csrf.middleware import csrf_exempt

# system
import json
import subprocess

def command(request, id):
    debug = False
    obj = get_object_or_404(Command, endpoint=id)

    command = obj.command.split()

    # if we have POST, lets try and unpack the data
    if request.method == 'POST':
        debug = request.POST.get('debug', False)

        if obj.accept_args:
            args = request.POST.get('args', '')
            command += args.split(",")

    p1 = subprocess.Popen( command, stdout=subprocess.PIPE)
    raw = p1.communicate()

    output = {
            'stdout': raw[0],
            'stderr': raw[1],
    }

    if debug:
        output['command'] = command

    response = json.dumps(output)

    return HttpResponse(response, mimetype='application/json')

#command = csrf_exempt(command)
