/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning.o -> touchlink_commissioning_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_commissioning_cluster_srv_cmd_proc_handler(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte bVar8;
  char cVar9;
  undefined2 *puVar10;
  byte bStack_4c;
  byte bStack_4b;
  ushort uStack_4a;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*(char *)(param_1 + 0x20) == 'A') {
    uStack_4a = 0;
    bStack_4c = 0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4a,&bStack_4c);
    if (uVar4 < uStack_4a) {
_L0:
      uVar7 = 0x80;
      goto _L0;
    }
    bVar8 = 0;
    puVar10 = (undefined2 *)0x0;
    uVar7 = zmsg_get_length(uStack_24);
    zmsg_append_u8(uStack_24,0);
    zmsg_append_u8(uStack_24,bStack_4c);
    uVar6 = zmsg_get_length(uStack_24);
    zmsg_append_u8(uStack_24,0);
    bVar2 = 0;
    while (puVar10 = (undefined2 *)
                     aps_group_table_next_by_endpoint(*(undefined1 *)(param_1 + 0x15),puVar10),
          puVar10 != (undefined2 *)0x0) {
      if (bStack_4c <= bVar8) {
        bVar2 = bVar2 + 1;
        zmsg_append_le16(uStack_24,*puVar10);
        zmsg_append_u8(uStack_24,0);
      }
      bVar8 = bVar8 + 1;
    }
    bStack_4b = bVar8;
    zmsg_write_bytes(uStack_24,uVar7,1,&bStack_4b);
    bStack_4b = bVar2;
    zmsg_write_bytes(uStack_24,uVar6,1,&bStack_4b);
    uVar7 = 0x41;
  }
  else {
    if (*(char *)(param_1 + 0x20) != 'B') {
      uVar7 = 0x81;
_L0:
      iVar3 = zcl_packet_setup_default_response(auStack_48,param_1,uVar7);
      goto _L0;
    }
    uStack_4a = 0;
    bStack_4c = 0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4a,&bStack_4c);
    bVar2 = bStack_4c;
    if (uVar4 < uStack_4a) goto _L0;
    iVar3 = 0;
    cVar1 = '\0';
    do {
      cVar9 = cVar1;
      iVar3 = ezb_af_get_next_simple_desc(iVar3);
      cVar1 = cVar9 + '\x01';
    } while (iVar3 != 0);
    zmsg_append_u8(uStack_24,cVar9);
    bVar8 = 0;
    zmsg_append_u8(uStack_24,bVar2);
    zmsg_append_u8(uStack_24,0);
    bVar2 = 0;
    puVar5 = (undefined1 *)0x0;
    while (puVar5 = (undefined1 *)ezb_af_get_next_simple_desc(puVar5), uVar7 = uStack_24,
          puVar5 != (undefined1 *)0x0) {
      if (bStack_4c <= bVar8) {
        uVar6 = nwk_get_short_address();
        zmsg_append_le16(uVar7,uVar6);
        bVar2 = bVar2 + 1;
        zmsg_append_u8(uStack_24,*puVar5);
        zmsg_append_le16(uStack_24,*(undefined2 *)(puVar5 + 2));
        zmsg_append_le16(uStack_24,*(undefined2 *)(puVar5 + 4));
        zmsg_append_u8(uStack_24,*(ushort *)(puVar5 + 6) & 0xf);
      }
      bVar8 = bVar8 + 1;
    }
    bStack_4b = bVar2;
    zmsg_write_bytes(uStack_24,2,1,&bStack_4b);
    uVar7 = 0x42;
  }
  iVar3 = zcl_packet_setup_response(auStack_48,param_1,uVar7);
_L0:
  if (iVar3 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar3;
}

