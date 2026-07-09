/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> ezb_zcl_time_server_synchronize_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_time_server_synchronize_time
              (undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined2 auStack_3c [2];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 *puStack_2c;
  code *pcStack_28;
  undefined4 uStack_24;
  
  iVar1 = 2;
  if (param_4 - 1U < 5) {
    iVar2 = time_server_get_time_ctx();
    iVar1 = 5;
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 4) != 0) {
        iVar1 = milli_timer_is_running(iVar2 + 0xc);
        if (iVar1 == 0) {
          uStack_38 = 0xfffd;
          *(undefined4 *)(iVar2 + 8) = param_3;
          uStack_34 = 0x104fffd;
          uStack_30 = 1;
          auStack_3c[0] = 10;
          puStack_2c = auStack_3c;
          pcStack_28 = zcl_time_server_sync_callback;
          uStack_24 = param_1;
          iVar1 = ezb_zdo_match_desc_req(&uStack_38);
          if (iVar1 != 0) {
            return iVar1;
          }
          milli_timer_start(iVar2 + 0xc,param_2 * 1000);
          *(char *)(iVar2 + 0x24) = (char)param_4;
          *(undefined2 *)(iVar2 + 0x1c) = 0xffff;
          *(undefined4 *)(iVar2 + 0x20) = 0xffffffff;
          return 0;
        }
      }
      iVar1 = 6;
    }
  }
  return iVar1;
}

