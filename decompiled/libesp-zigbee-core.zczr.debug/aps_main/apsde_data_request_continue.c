/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> apsde_data_request_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsde_data_request_continue(int *param_1,undefined2 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 auStack_12 [3];
  
  auStack_12[0] = param_2;
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x275,
                  "apsde_data_request_continue","req != ((void *)0) && req->asdu != ((void *)0)");
  }
  else {
    iVar3 = aps_is_shortaddr_bcast(param_2);
    if (iVar3 != 0) {
      bVar1 = *(byte *)(param_1 + 6);
      *(byte *)(param_1 + 6) = bVar1 & 0xfb;
      *(byte *)(param_1 + 6) = bVar1 & 0xf9;
    }
    if ((*(byte *)(param_1 + 6) & 2) == 0) {
      *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xfb;
    }
    uVar4 = zmsg_get_length(iVar2);
    uVar5 = param_1[6];
    uVar5 = aps_get_max_asdu(uVar5 >> 2 & 1,uVar5 & 1,uVar5 >> 3 & 1);
    if (uVar4 <= uVar5) {
      iVar2 = zmsg_add_footer(*param_1,param_1,0x1c);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = zmsg_add_footer(*param_1,auStack_12,2);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = core_globals_get();
      zmsg_queue_enqueue(iVar2 + 0x2c,*param_1);
      iVar2 = core_globals_get();
      tasklet_post(iVar2 + 0x1c);
      return 0;
    }
  }
  return 0x3a0;
}

