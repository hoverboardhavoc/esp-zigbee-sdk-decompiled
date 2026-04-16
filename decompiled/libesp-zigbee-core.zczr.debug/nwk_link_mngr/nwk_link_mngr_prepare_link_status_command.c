/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_prepare_link_status_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: status */
/* WARNING: Unknown calling convention */

ezb_shortaddr_t
nwk_link_mngr_prepare_link_status_command
          (zmsg_t *msg,uint8_t mac_iface,ezb_shortaddr_t start_addr,uint8_t max_count)

{
  ezb_shortaddr_t eVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  undefined2 uStack_24;
  undefined1 uStack_22;
  nwk_link_status status;
  
  uVar2 = CONCAT22(in_register_00002032,start_addr);
  zmsg_set_offset(0);
  uVar4 = nwk_get_short_address();
  nwk_frame_write_hdr(msg,uVar4,0xfffc,1,1,0);
  iVar5 = core_globals_get();
  uStack_24._0_1_ = *(char *)(iVar5 + 0x9d9);
  *(char *)(iVar5 + 0x9d9) = (char)uStack_24 + '\x01';
  zmsg_write_bytes(msg,7,1,&uStack_24);
  uStack_24._0_1_ = 8;
  zmsg_append_bytes(msg,1,&uStack_24);
  uStack_24 = (ushort)uStack_24._1_1_ << 8;
  zmsg_append_bytes(msg,1,&uStack_24);
  if (uVar2 == 0) goto _L0;
  bVar9 = 0;
_L7:
  uVar8 = 0;
  do {
    sVar3 = (short)uVar2;
    if ((0xfff7 < uVar2) || (CONCAT31(in_register_00002035,max_count) <= uVar8)) {
      while ((uVar2 < 0xfff8 &&
             (((iVar5 = nwk_neighbor_table_get_by_short(uVar2), iVar5 == 0 ||
               ((*(uint *)(iVar5 + 0xc) >> 0xd & 0x1f) != CONCAT31(in_register_0000202d,mac_iface)))
              || ((uVar7 = *(uint *)(iVar5 + 0xc) & 0x3c0, uVar7 != 0x80 && (uVar7 != 0x240))))))) {
        uVar2 = uVar2 + 1 & 0xffff;
      }
      if (uVar2 == 0xfff8) {
        bVar9 = bVar9 | 0x40;
        eVar1 = 0;
      }
      else {
        eVar1 = sVar3 - 1;
      }
      sVar3 = zmsg_get_offset(msg);
      uStack_24 = CONCAT11(uStack_24._1_1_,bVar9 | (byte)uVar8 & 0x1f);
      zmsg_write_bytes(msg,sVar3 + 1,1,&uStack_24);
      return eVar1;
    }
    iVar5 = nwk_neighbor_table_get_by_short(uVar2);
    if (((iVar5 != 0) &&
        ((*(uint *)(iVar5 + 0xc) >> 0xd & 0x1f) == CONCAT31(in_register_0000202d,mac_iface))) &&
       (((uVar7 = *(uint *)(iVar5 + 0xc) & 0x3c0, uVar7 == 0x80 || (uVar7 == 0x240)) &&
        (iVar6 = nwk_neighbor_get_incoming_cost(iVar5), iVar6 != 0)))) {
      uVar7 = *(uint *)(iVar5 + 0xc) & 3;
      if ((uVar7 != 0) && (uVar7 != 1)) break;
      uStack_24 = sVar3;
      uStack_22 = nwk_neighbor_get_link_status(iVar5);
      zmsg_append_bytes(msg,3,&uStack_24);
      uVar8 = uVar8 + 1 & 0xff;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while( true );
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_link_mngr.c",0x7f,
                "nwk_link_mngr_prepare_link_status_command",
                "nwk_device_type_is_zczr(nbr->device_type)");
_L0:
  bVar9 = 0x20;
  goto _L7;
}

