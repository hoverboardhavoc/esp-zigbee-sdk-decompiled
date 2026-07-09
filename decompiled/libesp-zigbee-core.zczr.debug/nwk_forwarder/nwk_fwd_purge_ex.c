/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_purge_ex
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_purge_ex(uint param_1,code *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort auStack_22 [5];
  
  puVar1 = s_nwk_fwd;
  while (puVar3 = DAT_00011a44, (undefined4 **)puVar1 != &s_nwk_fwd) {
    zmsg_read_bytes(puVar1,2,auStack_22);
    puVar3 = puVar1;
    if (((param_1 == 0xffff) || (auStack_22[0] == param_1)) &&
       ((param_2 == (code *)0x0 || (iVar2 = (*param_2)(puVar1,param_3), iVar2 != 0)))) {
      puVar3 = (undefined4 *)puVar1[1];
      zmsg_queue_dequeue(&s_nwk_fwd,puVar1);
      nwk_fwd_finish_tx(puVar1,8);
    }
    puVar1 = (undefined4 *)*puVar3;
  }
  while ((undefined4 **)puVar3 != &s_nwk_fwd) {
    zmsg_read_bytes(puVar3,2,auStack_22);
    puVar1 = puVar3;
    if (((param_1 == 0xffff) || (auStack_22[0] == param_1)) &&
       ((param_2 == (code *)0x0 || (iVar2 = (*param_2)(puVar3,param_3), iVar2 != 0)))) {
      puVar1 = (undefined4 *)puVar3[1];
      zmsg_tmque_dequeue(&s_nwk_fwd,puVar3);
      nwk_fwd_finish_tx(puVar3,8);
    }
    puVar3 = (undefined4 *)*puVar1;
  }
  return;
}

