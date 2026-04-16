/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_generate_rrec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zmsg_t * nwk_mesh_generate_rrec(ezb_shortaddr_t src_addr,ezb_shortaddr_t dst_addr)

{
  char cVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  zmsg_t *msg;
  int iVar3;
  undefined2 in_register_0000202e;
  uint uVar4;
  uint extraout_a1;
  undefined4 uVar5;
  undefined2 uStack_12;
  
  uVar4 = CONCAT22(in_register_0000202e,dst_addr);
  iVar2 = CONCAT22(in_register_0000202a,src_addr);
  if (0xfff7 < uVar4) {
    iVar2 = __assert_func(0,0,0,0);
    uVar4 = extraout_a1;
  }
  msg = (zmsg_t *)zmsg_alloc(0x27);
  if (msg != (zmsg_t *)0x0) {
    zmsg_append_u8(msg,'\x05');
    iVar3 = nwk_get_short_address();
    if (iVar3 == iVar2) {
      zmsg_append_u8(msg,'\0');
      uVar5 = 0xf;
    }
    else {
      zmsg_append_u8(msg,'\x01');
      uStack_12 = nwk_get_short_address();
      zmsg_append_bytes(msg,2,&uStack_12);
      uVar5 = 0xe;
    }
    zmsg_set_offset(msg,0);
    nwk_frame_write_hdr(msg,iVar2,uVar4,uVar5,1,0);
    iVar2 = core_globals_get();
    cVar1 = *(char *)(iVar2 + 0x9d9);
    *(char *)(iVar2 + 0x9d9) = cVar1 + '\x01';
    uStack_12 = CONCAT11(uStack_12._1_1_,cVar1);
    zmsg_write_bytes(msg,7,1,&uStack_12);
  }
  return msg;
}

