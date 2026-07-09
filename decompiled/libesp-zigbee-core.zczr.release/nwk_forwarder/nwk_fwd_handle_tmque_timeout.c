/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_tmque_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_tmque_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char cStack_13;
  short local_12 [3];
  
  zmsg_read_u8_isra_0(7,&cStack_13);
  zmsg_read_le16_isra_0(param_1,4,local_12);
  puVar5 = &s_nwk_fwd;
  iVar6 = 0;
  while ((*(short *)(puVar5 + 0xf) != local_12[0] || (*(char *)((int)puVar5 + 0x3e) != cStack_13)))
  {
    iVar6 = iVar6 + 1;
    puVar5 = puVar5 + 2;
    if (iVar6 == 0x5a) {
_L0:
      nwk_fwd_do_send_msg(param_1);
      return;
    }
  }
  uVar1 = (&DAT_000113ec)[iVar6 * 2];
  uVar2 = nwk_neighbor_table_get_capacity();
  uVar3 = bitmap_find_first_bit(uVar1,uVar2);
  uVar4 = nwk_neighbor_table_get_capacity();
  if (uVar4 <= uVar3) {
    nwk_fwd_finish_tx(param_1,0);
    return;
  }
  goto _L0;
}

