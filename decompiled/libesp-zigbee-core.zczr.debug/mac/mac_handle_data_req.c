/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_data_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_data_req(int param_1,int param_2)

{
  int *unaff_s0;
  int iVar1;
  int *piVar2;
  undefined1 auStack_38 [12];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  
  if (**(char **)(param_2 + 0x24) == '\x04') {
    uStack_2c = *(undefined2 *)(param_2 + 0xe);
    uStack_2a = *(undefined2 *)(param_2 + 0x10);
    uStack_28 = *(undefined2 *)(param_2 + 0x12);
    uStack_26 = *(undefined2 *)(param_2 + 0x14);
    uStack_24 = *(undefined2 *)(param_2 + 0x16);
    nwk_mm_poll_indication(*(undefined1 *)(param_1 + 0x2c),&uStack_2c);
    for (unaff_s0 = *(int **)(param_1 + 0x60); (int *)(param_1 + 0x60) != unaff_s0;
        unaff_s0 = (int *)*unaff_s0) {
      zmsg_get_footer(unaff_s0,auStack_38,10);
      iVar1 = ezb_address_compare(auStack_38,param_2 + 0xe);
      if (iVar1 != 0) goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x409,"mac_handle_data_req"
                  ,"*cmd_ptr++ == 4U");
_L0:
    piVar2 = (int *)unaff_s0[1];
    iVar1 = *unaff_s0;
    *(int **)(iVar1 + 4) = piVar2;
    *piVar2 = iVar1;
    *unaff_s0 = 0;
    unaff_s0[1] = 0;
    zmsg_queue_enqueue(param_1 + 0x54,unaff_s0);
    mac_start_op(param_1,8);
  }
  return;
}

