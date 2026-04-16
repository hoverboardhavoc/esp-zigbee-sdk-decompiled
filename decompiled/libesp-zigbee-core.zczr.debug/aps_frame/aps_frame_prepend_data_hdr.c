/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_prepend_data_hdr
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
  int iVar3;
  char *pcVar4;
  ezb_err_t eVar5;
  undefined4 uVar6;
  uint16_t *puVar7;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  undefined3 in_register_0000203d;
  uint16_t *puVar8;
  undefined4 uStack_3c;
  secur_aux_hdr_t aux_hdr;
  undefined1 local_2a;
  undefined1 uStack_29;
  uint8_t aps_hdr [12];
  
  stack0xffffffd4 = 0;
  aps_hdr[0] = '\0';
  aps_hdr[1] = '\0';
  aps_hdr[2] = '\0';
  aps_hdr[3] = '\0';
  aps_hdr[4] = '\0';
  aps_hdr[5] = '\0';
  aps_hdr[6] = '\0';
  aps_hdr[7] = '\0';
  if (addr->grp_addr == 0) {
    if (addr->dst_addr < 0xfff8) {
      bVar2 = 0;
    }
    else {
      bVar2 = 8;
    }
  }
  else {
    bVar2 = 0xc;
  }
  if (CONCAT31(in_register_00002035,is_secured) == 0) {
_L0:
    uVar6 = stack0xffffffd4;
    if (((bVar2 & 0xc) == 0) && (CONCAT31(in_register_00002031,is_ack_required) != 0)) {
      bVar2 = bVar2 | 0x40;
    }
    if (CONCAT31(in_register_00002039,is_fragmented) != 0) {
      bVar2 = bVar2 | 0x80;
    }
    stack0xffffffd4 = CONCAT31(stack0xffffffd5,bVar2);
    if ((bVar2 & 0xc) != 0xc) {
      _local_2a = SUB42(uVar6,2);
      aux_hdr._12_2_ = CONCAT11(addr->dst_ep,bVar2);
      puVar8 = (uint16_t *)&local_2a;
      goto _L0;
    }
  }
  else {
    bVar2 = bVar2 | 0x20;
    uStack_3c = 0;
    aux_hdr._0_4_ = 0;
    aux_hdr._4_4_ = 0;
    aux_hdr.src_address.field_0.u64._3_2_ = 0;
    if (CONCAT31(in_register_0000203d,inc_ext_nonce) == 0) {
      uVar6 = 5;
    }
    else {
      uStack_3c = 0x20;
      uVar6 = 0xd;
    }
    iVar3 = zmsg_prepend_bytes(msg,uVar6,&uStack_3c);
    if (iVar3 == 0) goto _L0;
    __assert_func("//build/esp-zigbee/src/core/aps/aps_frame.c",0xd9,"aps_frame_prepend_data_hdr",
                  "(zmsg_prepend_bytes(msg, aux_hdr_size, &aux_hdr)) == 0");
  }
  uVar6 = stack0xffffffd4;
  aux_hdr._12_2_ = CONCAT11((uint8_t)addr->grp_addr,aux_hdr.src_address.field_0.u8[7]);
  uStack_29 = SUB41(uVar6,3);
  stack0xffffffd4 = CONCAT12((char)(addr->grp_addr >> 8),aux_hdr._12_2_);
  puVar8 = (uint16_t *)&uStack_29;
_L0:
  *puVar8 = addr->cluster_id;
  puVar8[1] = addr->profile_id;
  *(uint8_t *)(puVar8 + 2) = addr->src_ep;
  pcVar4 = (char *)core_globals_get();
  cVar1 = *pcVar4;
  *pcVar4 = cVar1 + '\x01';
  *(char *)((int)puVar8 + 5) = cVar1;
  puVar7 = puVar8 + 3;
  if ((char)bVar2 < '\0') {
    *(undefined1 *)(puVar8 + 3) = 1;
    puVar7 = puVar8 + 4;
  }
  eVar5 = zmsg_prepend_bytes(msg,(int)puVar7 - (int)((int)&aux_hdr.src_address.field_0 + 7) & 0xffff
                            );
  return eVar5;
}

