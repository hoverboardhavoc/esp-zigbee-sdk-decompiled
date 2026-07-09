/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_active_ep_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_active_ep_req(undefined2 *param_1)

{
  int iVar1;
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
  if (param_1 == (undefined2 *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar1 = zdo_packet_init(&uStack_28,5,*param_1,*(undefined4 *)(param_1 + 2),
                            *(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
      iVar1 = zdo_op_active_ep_req(uStack_14,param_1 + 1,1);
      if (iVar1 == 0) {
        zdo_packet_send(&uStack_28);
        iVar1 = zdp_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
      else {
        iVar1 = 1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zdo_packet_free(&uStack_28);
  return iVar1;
}

