import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/valtec/aether/aether_ws/install/aether_gcs_ui'
