#!/usr/bin/env python
import os
import site
import sys

# Remember original sys.path.
prev_sys_path = list(sys.path)

# we add currently directory to path and change to it
pwd = os.path.dirname(os.path.abspath(__file__))
os.chdir(pwd)
sys.path = [pwd] + sys.path

# find the site-packages within the local virtualenv
for python_dir in os.listdir('lib'):
    site_packages_dir = os.path.join('lib', python_dir, 'site-packages')
    if os.path.exists(site_packages_dir):
        site.addsitedir(os.path.abspath(site_packages_dir))

# Reorder sys.path so new directories at the front.
new_sys_path = []
for item in list(sys.path):
    if item not in prev_sys_path:
        new_sys_path.append(item)
        sys.path.remove(item)
sys.path[:0] = new_sys_path

# grab our project path
cwd = os.path.dirname(os.path.abspath(__file__))
sys.path.append(cwd)
sys.path.append(cwd + '/arbitrary_sysadmin_api')

# now start django
from django.core.handlers.wsgi import WSGIHandler
os.environ['DJANGO_SETTINGS_MODULE'] = 'app1.settings'
application = WSGIHandler()
