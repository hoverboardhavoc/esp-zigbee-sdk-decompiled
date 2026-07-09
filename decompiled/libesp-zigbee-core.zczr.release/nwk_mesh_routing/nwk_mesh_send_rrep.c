/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_send_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_send_rrep(int param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 extraout_a1;
  byte bVar4;
  char cVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte bStack_38;
  undefined1 uStack_37;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined1 uStack_32;
  undefined1 auStack_31 [8];
  undefined1 auStack_29 [13];
  
  uVar7 = param_5;
  uVar8 = param_6;
  if (param_1 != 0) goto _L60;
  do {
    param_4 = 0;
    param_3 = 0;
    __assert_func(0,0);
    uVar7 = param_5;
    uVar8 = param_6;
    param_2 = extraout_a1;
_L60:
    param_5 = uVar7;
    param_6 = uVar8;
    zmsg_free();
    iVar1 = zmsg_alloc(0x2f);
  } while (iVar1 == 0);
  zmsg_set_offset(0);
  uVar2 = nwk_get_short_address();
  nwk_frame_write_hdr(iVar1,uVar2,uVar8,0,1,0);
  iVar3 = core_globals_get();
  bStack_38 = *(byte *)(iVar3 + 0x9d9);
  *(byte *)(iVar3 + 0x9d9) = bStack_38 + 1;
  zmsg_write_bytes(iVar1,7,1,&bStack_38);
  memset(&bStack_38,0,0x17);
  uStack_36 = (undefined2)param_4;
  uStack_34 = (undefined2)uVar7;
  uStack_37 = param_2;
  uStack_32 = param_3;
  iVar3 = nwk_address_extended_by_short(param_4,auStack_31);
  puVar6 = auStack_31;
  if (iVar3 == 0) {
    puVar6 = auStack_29;
    bStack_38 = bStack_38 | 0x10;
  }
  iVar3 = nwk_address_extended_by_short(uStack_34,puVar6);
  if (iVar3 == 0) {
    bStack_38 = bStack_38 | 0x20;
  }
  zmsg_append_u8_isra_0(iVar1,2);
  bVar4 = bStack_38 >> 1 & 8;
  cVar5 = bVar4 + 7;
  if ((bStack_38 & 0x20) != 0) {
    cVar5 = bVar4 + 0xf;
  }
  zmsg_append_bytes(iVar1,cVar5,&bStack_38);
  nwk_fwd_send_msg_delayed(iVar1,0);
  return;
}

