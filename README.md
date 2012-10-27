

**arbitrary-sysadmin-api**

django web admin interface for creating arbitrary API endpoints that optionally take a POST body and execute system commands.

for example:
	/media_restart runs `/etc/init.d/xbmc restart`
	/notify runs `/usr/bin/notify-send POST['message']`


