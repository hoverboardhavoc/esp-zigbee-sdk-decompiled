/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_build_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_build_leave(zmsg_t *msg,ezb_shortaddr_t dst_addr,_Bool rejoin,_Bool remove_children)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 in_register_0000202e;
  char acStack_21 [13];
  
  uVar1 = nwk_get_short_address();
  nwk_frame_write_hdr(msg,uVar1,CONCAT22(in_register_0000202e,dst_addr),1,1,0);
  iVar2 = core_globals_get();
  acStack_21[0] = *(char *)(iVar2 + 0x9d9);
  *(char *)(iVar2 + 0x9d9) = acStack_21[0] + '\x01';
  zmsg_write_bytes(msg,7,1,acStack_21);
  zmsg_append_u8(msg,'\x04');
  zmsg_append_bytes(msg,1,&stack0xffffffef);
  return;
}

