/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> ezb_zcl_time_server_synchronize_time
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
  
  if (param_4 - 1U < 5) {
    iVar1 = time_server_get_time_ctx();
    if (iVar1 == 0) {
      iVar2 = 5;
    }
    else if (*(int *)(iVar1 + 4) == 0) {
      iVar2 = 6;
    }
    else {
      iVar2 = milli_timer_is_running(iVar1 + 0xc);
      if (iVar2 == 0) {
        *(undefined4 *)(iVar1 + 8) = param_3;
        iVar2 = zcl_time_server_sync_start(param_1);
        if (iVar2 == 0) {
          milli_timer_start(iVar1 + 0xc,param_2 * 1000);
          *(char *)(iVar1 + 0x24) = (char)param_4;
          *(undefined2 *)(iVar1 + 0x1c) = 0xffff;
          *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
        }
      }
      else {
        iVar2 = 6;
      }
    }
  }
  else {
    iVar2 = 2;
  }
  return iVar2;
}

