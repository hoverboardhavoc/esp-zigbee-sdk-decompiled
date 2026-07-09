/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_device_service_discovery_req_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    return 0x80;
  }
  iVar2 = zdo_packet_response_init(&uStack_28,param_1,*(ushort *)(param_1 + 6) | 0x8000);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = *(ushort *)(param_1 + 6);
  if (uVar1 == 5) {
    iVar2 = zdo_active_ep_req_handler(param_1,&uStack_28);
  }
  else if (uVar1 < 6) {
    if (uVar1 == 2) {
      iVar2 = zdo_node_desc_req_handler(param_1,&uStack_28);
    }
    else if (uVar1 < 3) {
      if (uVar1 == 0) {
        iVar2 = zdo_nwk_addr_req_handler(param_1,&uStack_28);
      }
      else {
        if (uVar1 != 1) {
          iVar2 = 0x84;
          goto _L0;
        }
        iVar2 = zdo_ieee_addr_req_handler(param_1,&uStack_28);
      }
    }
    else if (uVar1 == 3) {
      iVar2 = zdo_power_desc_req_handler(param_1,&uStack_28);
    }
    else {
      if (uVar1 != 4) {
        iVar2 = 0x84;
        goto _L0;
      }
      iVar2 = zdo_simple_desc_req_handler(param_1,&uStack_28);
    }
  }
  else if (uVar1 == 0x15) {
    iVar2 = zdo_sys_srv_disc_req_handler(param_1,&uStack_28);
  }
  else if (uVar1 < 0x16) {
    if (uVar1 == 6) {
      iVar2 = zdo_match_desc_req_handler(param_1,&uStack_28);
    }
    else {
      if (uVar1 != 0x13) {
        iVar2 = 0x84;
        goto _L0;
      }
      iVar2 = zdo_device_annce_handler(param_1);
    }
  }
  else {
    if (uVar1 != 0x1f) {
      iVar2 = 0x84;
      goto _L0;
    }
    iVar2 = zdo_parent_annce_handler(param_1,&uStack_28);
  }
  if (iVar2 == 0) {
    iVar2 = zdo_packet_send(&uStack_28);
    return iVar2;
  }
_L0:
  zdo_packet_free(&uStack_28);
  return iVar2;
}

