/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_device_service_discovery_rsp_handler(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 6);
    if (uVar1 == 0x8004) {
      uVar2 = zdo_simple_desc_rsp_handler();
    }
    else if (uVar1 < 0x8005) {
      if (uVar1 == 0x8002) {
        uVar2 = zdo_node_desc_rsp_handler();
      }
      else if (uVar1 < 0x8003) {
        if ((ushort)(uVar1 + 0x8000) < 2) {
          uVar2 = zdo_addr_rsp_handler();
        }
        else {
          uVar2 = 0x84;
        }
      }
      else if (uVar1 == 0x8003) {
        uVar2 = zdo_power_desc_rsp_handler();
      }
      else {
        uVar2 = 0x84;
      }
    }
    else if (uVar1 == 0x8006) {
      uVar2 = zdo_match_desc_rsp_handler();
    }
    else if (uVar1 == 0x8015) {
      uVar2 = zdo_sys_srv_disc_rsp_handler();
    }
    else if (uVar1 == 0x8005) {
      uVar2 = zdo_active_ep_rsp_handler();
    }
    else {
      uVar2 = 0x84;
    }
  }
  return uVar2;
}

