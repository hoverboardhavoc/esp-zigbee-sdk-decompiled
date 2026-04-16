/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_prepend_data_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_frame_prepend_data_hdr
                    (zmsg_t *msg,aps_addr_t *addr,_Bool is_ack_required,_Bool is_secured,
                    _Bool is_fragmented,_Bool inc_ext_nonce)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint16_t *puVar4;
  int iVar5;
  char *pcVar6;
  ezb_err_t eVar7;
  undefined4 uVar8;
  undefined3 in_register_00002035;
  undefined3 in_register_0000203d;
  byte bStack_3c;
  uint8_t uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  uint8_t aps_hdr [12];
  secur_aux_hdr_t aux_hdr;
  
  _bStack_3c = 0;
  aps_hdr[0] = '\0';
  aps_hdr[1] = '\0';
  aps_hdr[2] = '\0';
  aps_hdr[3] = '\0';
  aps_hdr[4] = '\0';
  aps_hdr[5] = '\0';
  aps_hdr[6] = '\0';
  aps_hdr[7] = '\0';
  if (addr->grp_addr == 0) {
    uVar3 = (uint)(0xfff7 < addr->dst_addr) << 3;
    if (CONCAT31(in_register_00002035,is_secured) != 0) goto _L0;
  }
  else {
    uVar3 = 0xc;
    if (CONCAT31(in_register_00002035,is_secured) == 0) goto _L0;
_L0:
    aps_hdr[8] = '\0';
    aps_hdr[9] = '\0';
    aps_hdr[10] = '\0';
    aps_hdr[0xb] = '\0';
    uVar3 = uVar3 | 0x20;
    uVar8 = 5;
    if (CONCAT31(in_register_0000203d,inc_ext_nonce) != 0) {
      aps_hdr[8] = ' ';
      aps_hdr[9] = '\0';
      aps_hdr[10] = '\0';
      aps_hdr[0xb] = '\0';
      uVar8 = 0xd;
    }
    iVar5 = zmsg_prepend_bytes(msg,uVar8,aps_hdr + 8);
    if (iVar5 != 0) {
      __assert_func(0,0,0,0);
    }
  }
  if ((uVar3 & 0xc) == 0) {
    uVar3 = uVar3 | (is_ack_required & 3) << 6;
  }
_L0:
  uVar8 = _bStack_3c;
  bVar2 = (byte)uVar3 | is_fragmented << 7;
  if ((uVar3 & 0xc) == 0xc) {
    puVar4 = (uint16_t *)&uStack_39;
    _bStack_3c = CONCAT11((char)addr->grp_addr,bVar2);
    uStack_39 = SUB41(uVar8,3);
    _bStack_3c = CONCAT12((char)(addr->grp_addr >> 8),_bStack_3c);
  }
  else {
    puVar4 = (uint16_t *)&uStack_3a;
    _bStack_3c = CONCAT11(addr->dst_ep,bVar2);
  }
  *puVar4 = addr->cluster_id;
  puVar4[1] = addr->profile_id;
  *(uint8_t *)(puVar4 + 2) = addr->src_ep;
  pcVar6 = (char *)core_globals_get();
  cVar1 = *pcVar6;
  *pcVar6 = cVar1 + '\x01';
  *(char *)((int)puVar4 + 5) = cVar1;
  if ((char)bVar2 < '\0') {
    *(undefined1 *)(puVar4 + 3) = 1;
    puVar4 = puVar4 + 4;
  }
  else {
    puVar4 = puVar4 + 3;
  }
  eVar7 = zmsg_prepend_bytes(msg,(int)puVar4 - (int)&bStack_3c & 0xffff);
  return eVar7;
}

