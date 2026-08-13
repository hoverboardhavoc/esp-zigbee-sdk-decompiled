/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  while (puVar3 = DAT_00011a5c, (undefined4 **)puVar1 != &s_nwk_fwd) {
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

