/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_send_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_send_rrep(zmsg_t *rreq_msg,uint8_t rreq_id,uint8_t path_cost,
                       ezb_shortaddr_t originator,ezb_shortaddr_t responder,ezb_shortaddr_t sender)

{
  zmsg_t *msg;
  undefined4 uVar1;
  int iVar2;
  uint8_t extraout_a1;
  byte bVar3;
  char cVar4;
  undefined1 *puVar5;
  undefined2 in_register_00002036;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 in_register_0000203e;
  undefined4 uVar9;
  byte bStack_38;
  uint8_t uStack_37;
  undefined2 uStack_36;
  nwk_rrep_cmd_t rrep;
  
  uVar1 = CONCAT22(in_register_0000203e,sender);
  uVar7 = (uint)responder;
  uVar6 = CONCAT22(in_register_00002036,originator);
  uVar8 = uVar7;
  uVar9 = uVar1;
  if (rreq_msg != (zmsg_t *)0x0) goto _L60;
  do {
    uVar6 = 0;
    path_cost = '\0';
    __assert_func(0,0);
    uVar8 = uVar7;
    uVar9 = uVar1;
    rreq_id = extraout_a1;
_L60:
    uVar7 = uVar8;
    uVar1 = uVar9;
    zmsg_free();
    msg = (zmsg_t *)zmsg_alloc(0x2f);
  } while (msg == (zmsg_t *)0x0);
  zmsg_set_offset(0);
  uVar1 = nwk_get_short_address();
  nwk_frame_write_hdr(msg,uVar1,uVar9,0,1,0);
  iVar2 = core_globals_get();
  bStack_38 = *(byte *)(iVar2 + 0x9d9);
  *(byte *)(iVar2 + 0x9d9) = bStack_38 + 1;
  zmsg_write_bytes(msg,7,1,&bStack_38);
  memset(&bStack_38,0,0x17);
  uStack_36 = (undefined2)uVar6;
  rrep._0_2_ = (undefined2)uVar8;
  uStack_37 = rreq_id;
  rrep.orig_addr._0_1_ = path_cost;
  iVar2 = nwk_address_extended_by_short(uVar6,(undefined1 *)((int)&rrep.orig_addr + 1));
  puVar5 = (undefined1 *)((int)&rrep.orig_addr + 1);
  if (iVar2 == 0) {
    puVar5 = (undefined1 *)((int)&rrep.orig_ieee_addr.field_0 + 4);
    bStack_38 = bStack_38 | 0x10;
  }
  iVar2 = nwk_address_extended_by_short(rrep._0_2_,puVar5);
  if (iVar2 == 0) {
    bStack_38 = bStack_38 | 0x20;
  }
  zmsg_append_u8(msg,'\x02');
  bVar3 = bStack_38 >> 1 & 8;
  cVar4 = bVar3 + 7;
  if ((bStack_38 & 0x20) != 0) {
    cVar4 = bVar3 + 0xf;
  }
  zmsg_append_bytes(msg,cVar4,&bStack_38);
  nwk_fwd_send_msg_delayed(msg,0);
  return;
}

