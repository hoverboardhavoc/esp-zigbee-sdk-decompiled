/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_frame.o -> nwk_frame_write_hdr
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
  uint uVar2;
  int iVar3;
  ezb_err_t eVar4;
  uint uVar5;
  undefined2 in_register_0000202e;
  ezb_shortaddr_t *peVar6;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  undefined3 in_register_0000203d;
  undefined3 in_register_00002041;
  int iVar7;
  int iVar8;
  undefined4 uStack_58;
  nwk_sroute_field_t sroute;
  undefined2 uStack_48;
  ezb_shortaddr_t eStack_46;
  nwk_hdr_t nwk_hdr;
  
  iVar8 = CONCAT31(in_register_00002035,radius);
  memset(&uStack_48,0,0x18);
  iVar3 = core_globals_get();
  iVar7 = 0;
  if (*(char *)(iVar3 + 0x9f7) != '\0') {
    iVar7 = nwk_route_record_table_find(CONCAT22(in_register_00002032,dst_addr));
  }
  eVar4 = 2;
  if (msg != (zmsg_t *)0x0) {
    uVar2 = CONCAT31(in_register_00002039,is_command) + 8U |
            CONCAT31(in_register_00002041,disc_route) << 6;
    if (CONCAT31(in_register_0000203d,is_secured) != 0) {
      uStack_58 = 0;
      _sroute = 0;
      iVar3 = zmsg_prepend_bytes(msg,0xe,&uStack_58);
      uVar2 = uVar2 | 0x200;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((iVar7 != 0) &&
       (bVar1 = *(byte *)(iVar7 + 2), iVar3 = zmsg_get_length(msg),
       (int)(iVar3 + (bVar1 + 1) * 2) < 0x69)) {
      bVar1 = *(byte *)(iVar7 + 2);
      uStack_58._0_2_ = CONCAT11(bVar1,bVar1);
      iVar3 = zmsg_prepend_bytes(msg,(uint)bVar1 << 1,iVar7 + 4);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = zmsg_prepend_bytes(msg,2,&uStack_58);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar2 = uVar2 | 0x400;
    }
    if (iVar8 == 0) {
      iVar8 = 0x1e;
    }
    nwk_hdr.dst_addr._0_1_ = (undefined1)iVar8;
    eStack_46 = dst_addr;
    nwk_hdr.fcf = src_addr;
    uVar5 = zmsg_get_length(msg);
    if (uVar5 < 0x59) {
      iVar3 = nwk_address_extended_by_short
                        (CONCAT22(in_register_00002032,dst_addr),&nwk_hdr.src_addr);
      peVar6 = &nwk_hdr.src_addr;
      if (iVar3 == 0) {
        uVar2 = uVar2 | 0x800;
        peVar6 = (ezb_shortaddr_t *)((int)&nwk_hdr.dst_ieee_addr.field_0 + 4);
      }
      iVar3 = nwk_address_extended_by_short(CONCAT22(in_register_0000202e,src_addr),peVar6);
      if (iVar3 == 0) {
        uVar2 = uVar2 | 0x1000;
      }
    }
    uVar5 = uVar2 >> 8 & 8;
    uStack_48 = (undefined2)uVar2;
    iVar3 = uVar5 + 8;
    if ((int)(uVar2 << 0x13) < 0) {
      iVar3 = uVar5 + 0x10;
    }
    eVar4 = zmsg_prepend_bytes(msg,iVar3,&uStack_48);
  }
  return eVar4;
}

