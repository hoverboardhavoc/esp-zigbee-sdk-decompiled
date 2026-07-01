/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_rsp_handler(void *arg)

{
  ushort uVar1;
  zdp_status_t zVar2;
  
  if (arg == (void *)0x0) {
    zVar2 = 0x80;
  }
  else {
    uVar1 = *(ushort *)((int)arg + 6);
    if (uVar1 == 0x8034) {
      zVar2 = zdo_nwk_mgmt_leave_rsp_handler((zdo_packet_t *)arg);
    }
    else if (uVar1 < 0x8035) {
      if (uVar1 == 0x8032) {
        zVar2 = zdo_nwk_mgmt_rtg_rsp_handler((zdo_packet_t *)arg);
      }
      else if (uVar1 == 0x8033) {
        zVar2 = zdo_nwk_mgmt_bind_rsp_handler((zdo_packet_t *)arg);
      }
      else if (uVar1 == 0x8031) {
        zVar2 = zdo_nwk_mgmt_lqi_rsp_handler((zdo_packet_t *)arg);
      }
      else {
        zVar2 = 0x84;
      }
    }
    else if (uVar1 == 0x8036) {
      zVar2 = zdo_nwk_mgmt_permit_joining_rsp_handler((zdo_packet_t *)arg);
    }
    else if (uVar1 == 0x8038) {
      zVar2 = zdo_nwk_mgmt_nwk_update_notify_handler((zdo_packet_t *)arg);
    }
    else {
      zVar2 = 0x84;
    }
  }
  return zVar2;
}

