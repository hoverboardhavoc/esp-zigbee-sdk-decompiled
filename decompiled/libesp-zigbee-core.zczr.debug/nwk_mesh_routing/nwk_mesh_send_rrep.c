/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_send_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_send_rrep(zmsg_t *rreq_msg,uint8_t rreq_id,uint8_t path_cost,
                       ezb_shortaddr_t originator,ezb_shortaddr_t responder,ezb_shortaddr_t sender)

{
  int unaff_s0;
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 in_register_00002036;
  undefined2 in_register_0000203e;
  char cStack_39;
  uint uStack_38;
  nwk_rrep_cmd_t rrep;
  
  if (rreq_msg == (zmsg_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_mesh_routing.c",0xc3,"nwk_mesh_send_rrep",
                  "rreq_msg != ((void *)0)");
_L0:
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_mesh_routing.c",199,"nwk_mesh_send_rrep",
                  "rreq_msg != ((void *)0)");
  }
  else {
    zmsg_free();
    unaff_s0 = zmsg_alloc(0x2f);
    if (unaff_s0 == 0) goto _L0;
    zmsg_set_offset(0);
    uVar1 = nwk_get_short_address();
    nwk_frame_write_hdr(unaff_s0,uVar1,CONCAT22(in_register_0000203e,sender),0,1,0);
    iVar2 = core_globals_get();
    cStack_39 = *(char *)(iVar2 + 0x9d9);
    *(char *)(iVar2 + 0x9d9) = cStack_39 + '\x01';
    zmsg_write_bytes(unaff_s0,7,1,&cStack_39);
    rrep._4_4_ = 0;
    rrep.orig_ieee_addr.field_0.u64._1_4_ = 0;
    rrep._12_4_ = 0;
    rrep.resp_ieee_addr.field_0.u64._1_2_ = 0;
    rrep.resp_ieee_addr.field_0.u8[3] = '\0';
    uStack_38 = (uint)CONCAT21(originator,rreq_id) << 8;
    rrep.orig_addr._0_1_ = path_cost;
    rrep._0_2_ = responder;
    rrep.orig_addr._1_1_ = 0;
    iVar2 = nwk_address_extended_by_short
                      (CONCAT22(in_register_00002036,originator),
                       (undefined1 *)((int)&rrep.orig_addr + 1));
    if (iVar2 == 0) {
      uStack_38 = uStack_38 | 0x10;
      puVar3 = (undefined1 *)((int)&rrep.orig_ieee_addr.field_0 + 4);
      goto _L0;
    }
  }
  puVar3 = (undefined1 *)((int)&rrep.orig_addr + 1);
_L0:
  iVar2 = nwk_address_extended_by_short(rrep._0_4_ & 0xffff,puVar3);
  if (iVar2 == 0) {
    uStack_38 = uStack_38 | 0x20;
  }
  cStack_39 = '\x02';
  zmsg_append_bytes(unaff_s0,1,&cStack_39);
  if ((uStack_38 & 0x10) == 0) {
    iVar2 = 7;
  }
  else {
    iVar2 = 0xf;
  }
  if ((uStack_38 & 0x20) != 0) {
    iVar2 = iVar2 + 8;
  }
  zmsg_append_bytes(unaff_s0,iVar2,&uStack_38);
  nwk_fwd_send_msg(unaff_s0);
  return;
}

