/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_frame_write_hdr(zmsg_t *msg,ezb_shortaddr_t src_addr,ezb_shortaddr_t dst_addr,
                             uint8_t radius,_Bool is_command,_Bool is_secured,_Bool disc_route)

{
  byte bVar1;
  int iVar2;
  uint8_t uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ezb_err_t eVar7;
  undefined2 in_register_0000202e;
  ezb_shortaddr_t *peVar8;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  undefined3 in_register_0000203d;
  undefined3 in_register_00002041;
  ushort fcf;
  byte bStack_5c;
  byte bStack_5b;
  nwk_sroute_field_t sroute;
  ezb_shortaddr_t eStack_56;
  nwk_hdr_t nwk_hdr;
  
  iVar2 = CONCAT31(in_register_00002035,radius);
  _sroute = 0;
  nwk_hdr.fcf = 0;
  nwk_hdr.dst_addr = 0;
  nwk_hdr.src_addr = 0;
  nwk_hdr.radius = '\0';
  nwk_hdr.seq_num = '\0';
  nwk_hdr.dst_ieee_addr.field_0.u64._0_4_ = 0;
  nwk_hdr.dst_ieee_addr.field_0.u64._4_4_ = 0;
  nwk_hdr.src_ieee_addr.field_0.u64._0_4_ = 0;
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0x9f7) == '\0') {
    iVar4 = 0;
  }
  else {
    iVar4 = nwk_route_record_table_find(CONCAT22(in_register_00002032,dst_addr));
  }
  if (msg == (zmsg_t *)0x0) {
    eVar7 = 2;
  }
  else {
    if (CONCAT31(in_register_00002039,is_command) == 0) {
      fcf = 8;
    }
    else {
      fcf = 9;
    }
    if (CONCAT31(in_register_00002041,disc_route) != 0) {
      fcf = fcf | 0x40;
    }
    if (CONCAT31(in_register_0000203d,is_secured) != 0) {
      fcf = fcf | 0x200;
      nwk_hdr.src_ieee_addr.field_0.u64._4_4_ = 0;
      iVar5 = zmsg_prepend_bytes(msg,0xe,(undefined1 *)((int)&nwk_hdr.src_ieee_addr.field_0 + 4));
      if (iVar5 != 0) {
        return iVar5;
      }
    }
    if ((iVar4 != 0) &&
       (bVar1 = *(byte *)(iVar4 + 2), iVar5 = zmsg_get_length(msg),
       (int)((bVar1 + 1) * 2 + iVar5) < 0x69)) {
      bStack_5c = *(byte *)(iVar4 + 2);
      fcf = fcf | 0x400;
      bStack_5b = bStack_5c;
      iVar4 = zmsg_prepend_bytes(msg,(uint)bStack_5c << 1,iVar4 + 4);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = zmsg_prepend_bytes(msg,2,&bStack_5c);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    _sroute = CONCAT22(dst_addr,sroute);
    if (iVar2 == 0) {
      iVar2 = 0x1e;
    }
    nwk_hdr.dst_addr._0_1_ = (char)iVar2;
    nwk_hdr.fcf = src_addr;
    uVar6 = zmsg_get_length(msg);
    if (uVar6 < 0x59) {
      iVar2 = nwk_address_extended_by_short
                        (CONCAT22(in_register_00002032,dst_addr),&nwk_hdr.src_addr);
      if (iVar2 == 0) {
        fcf = fcf | 0x800;
        peVar8 = (ezb_shortaddr_t *)((int)&nwk_hdr.dst_ieee_addr.field_0 + 4);
      }
      else {
        peVar8 = &nwk_hdr.src_addr;
      }
      iVar2 = nwk_address_extended_by_short(CONCAT22(in_register_0000202e,src_addr),peVar8);
      if (iVar2 == 0) {
        fcf = fcf | 0x1000;
      }
    }
    _sroute = CONCAT22(eStack_56,fcf);
    uVar3 = nwk_fcf_get_hdr_size(fcf);
    eVar7 = zmsg_prepend_bytes(msg,uVar3,&sroute);
  }
  return eVar7;
}

