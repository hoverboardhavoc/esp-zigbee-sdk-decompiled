/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_device_service_discovery_rsp_handler(void *arg)

{
  ushort uVar1;
  zdp_status_t zVar2;
  
  if (arg == (void *)0x0) {
    zVar2 = 0xfe;
  }
  else {
    uVar1 = *(ushort *)((int)arg + 6);
    if (uVar1 == 0x8004) {
      zVar2 = zdo_simple_desc_rsp_handler((zdo_packet_t *)arg);
    }
    else if (uVar1 < 0x8005) {
      if (uVar1 == 0x8002) {
        zVar2 = zdo_node_desc_rsp_handler((zdo_packet_t *)arg);
      }
      else if (uVar1 < 0x8003) {
        if ((ushort)(uVar1 + 0x8000) < 2) {
          zVar2 = zdo_addr_rsp_handler((zdo_packet_t *)arg);
        }
        else {
          zVar2 = 0x84;
        }
      }
      else if (uVar1 == 0x8003) {
        zVar2 = zdo_power_desc_rsp_handler((zdo_packet_t *)arg);
      }
      else {
        zVar2 = 0x84;
      }
    }
    else if (uVar1 == 0x8005) {
      zVar2 = zdo_active_ep_rsp_handler((zdo_packet_t *)arg);
    }
    else if (uVar1 == 0x8006) {
      zVar2 = zdo_match_desc_rsp_handler((zdo_packet_t *)arg);
    }
    else {
      zVar2 = 0x84;
    }
  }
  return zVar2;
}

