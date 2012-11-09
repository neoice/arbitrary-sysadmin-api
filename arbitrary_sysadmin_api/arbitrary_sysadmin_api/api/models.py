from django.db import models

class Command(models.Model):
    endpoint = models.CharField(max_length=255)
    command = models.CharField(max_length=255)

    accept_args = models.BooleanField()

    def __unicode__(self):
        return self.endpoint
