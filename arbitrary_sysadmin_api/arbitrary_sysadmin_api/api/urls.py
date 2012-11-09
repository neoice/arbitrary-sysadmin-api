from django.conf.urls.defaults import *

urlpatterns = patterns('',
    (r'^(?P<id>\w+)/$', 'arbitrary_sysadmin_api.api.views.command'),
)
