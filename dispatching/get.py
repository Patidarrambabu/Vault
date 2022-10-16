import math 
import random
# required in future
def get_queryset(self):
    if DispatcherRoles.BROKER in self.request.user.get_all_roles:
        raise RestValidationError(
                detail={"message":"You don't have access to this api."},
                code=status.HTTP_403_FORBIDDEN
            )
    dcm = getattr(self.request.user, "dispatchcompanymembership", None)
    # print("DCMMMMMMMMM", dcm)
    if dcm:
        user_role = dcm.roles.all()