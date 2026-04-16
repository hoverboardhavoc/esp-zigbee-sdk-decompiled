/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_add_if_absent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_btt_add_if_absent(ezb_shortaddr_t src_addr,zmsg_t *msg)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  nwk_bt_record_t *pnVar3;
  nwk_bt_record_t *pnVar4;
  uint uVar5;
  uint8_t auStack_11 [4];
  uint8_t seq_num;
  
  iVar2 = core_globals_get();
  if ((uint)*(ushort *)(iVar2 + 0x9e2) == CONCAT22(in_register_0000202a,src_addr)) {
    _Var1 = false;
  }
  else {
    zmsg_read_bytes(msg,7,1,auStack_11);
    pnVar4 = (nwk_bt_record_t *)0x0;
    for (uVar5 = 0; uVar5 < 0x5a; uVar5 = uVar5 + 1 & 0xff) {
      pnVar3 = s_nwk_fwd.btt + uVar5;
      if (((s_nwk_fwd.btt[uVar5].expire_time != '\0') &&
          (pnVar3 = pnVar4,
          (uint)s_nwk_fwd.btt[uVar5].src_addr == CONCAT22(in_register_0000202a,src_addr))) &&
         (s_nwk_fwd.btt[uVar5].seq_num == auStack_11[0])) {
        return false;
      }
      pnVar4 = pnVar3;
    }
    if (pnVar4 == (nwk_bt_record_t *)0x0) {
      _Var1 = false;
    }
    else {
      pnVar4->src_addr = src_addr;
      pnVar4->seq_num = auStack_11[0];
      pnVar4->expire_time = '\t';
      time_ticker_register_receiver(0);
      _Var1 = true;
    }
  }
  return _Var1;
}

