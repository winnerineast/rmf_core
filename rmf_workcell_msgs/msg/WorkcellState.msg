builtin_interfaces/Time time

# A unique ID for this workcell
string guid

# Different basic modes that the workcell could be in
int32 mode
int32 IDLE=0
int32 BUSY=1
int32 OFFLINE=2

# The unique ID of the task/request that is currently being handled by this
# workcell, and how much more time it needs to complete it
string current_request_guid
float32 seconds_remaining

# Queued up requests that are waiting to be handled by this workcell
string[] request_guid_queue
