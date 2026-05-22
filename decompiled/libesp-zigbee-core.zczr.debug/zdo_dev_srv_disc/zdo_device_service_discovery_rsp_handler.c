/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    else if (uVar1 == 0x8006) {
      zVar2 = zdo_match_desc_rsp_handler((zdo_packet_t *)arg);
    }
    else if (uVar1 == 0x8015) {
      zVar2 = zdo_sys_srv_disc_rsp_handler((zdo_packet_t *)arg);
    }
    else if (uVar1 == 0x8005) {
      zVar2 = zdo_active_ep_rsp_handler((zdo_packet_t *)arg);
    }
    else {
      zVar2 = 0x84;
    }
  }
  return zVar2;
}

