/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_purge_ex
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_purge_ex(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort auStack_32 [7];
  
  for (puVar2 = s_nwk_fwd; puVar3 = puRam00011400, (undefined4 **)puVar2 != &s_nwk_fwd;
      puVar2 = (undefined4 *)*puVar2) {
    zmsg_read_le16_isra_0(puVar2,2,auStack_32);
    if (((param_1 == 0xffff) || (auStack_32[0] == param_1)) &&
       ((param_2 == (code *)0x0 || (iVar1 = (*param_2)(puVar2,param_3), iVar1 != 0)))) {
      puVar3 = (undefined4 *)puVar2[1];
      zmsg_queue_dequeue(&s_nwk_fwd,puVar2);
      nwk_fwd_finish_tx(puVar2,8);
      puVar2 = puVar3;
    }
  }
  for (; (undefined4 **)puVar3 != &s_nwk_fwd; puVar3 = (undefined4 *)*puVar3) {
    zmsg_read_le16_isra_0(puVar3,2,auStack_32);
    if (((param_1 == 0xffff) || (auStack_32[0] == param_1)) &&
       ((param_2 == (code *)0x0 || (iVar1 = (*param_2)(puVar3,param_3), iVar1 != 0)))) {
      puVar2 = (undefined4 *)puVar3[1];
      zmsg_tmque_dequeue(&s_nwk_fwd,puVar3);
      nwk_fwd_finish_tx(puVar3,8);
      puVar3 = puVar2;
    }
  }
  return;
}

