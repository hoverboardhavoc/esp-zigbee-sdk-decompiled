/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning.o -> touchlink_commissioning_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t touchlink_commissioning_cluster_srv_cmd_proc_handler(void *arg)

{
  uint8_t uVar1;
  byte bVar2;
  int iVar3;
  uint16_t val;
  undefined4 uVar4;
  uint uVar5;
  uint8_t *puVar6;
  undefined4 uVar7;
  byte bVar8;
  uint8_t val_00;
  uint16_t *puVar9;
  byte bStack_4c;
  byte bStack_4b;
  uint16_t uStack_4a;
  uint8_t start_index;
  uint16_t offset;
  zcl_packet_t resp;
  
  iVar3 = 1;
  memset(&start_index,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar3 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar3 = zcl_packet_init(&start_index,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar3 != 0))
  goto _L0;
  if (*(char *)((int)arg + 0x20) == 'A') {
    uStack_4a = 0;
    bStack_4c = 0;
    uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_4a,&bStack_4c);
    if (uStack_4a <= uVar5) {
      bVar8 = 0;
      puVar9 = (uint16_t *)0x0;
      uVar7 = zmsg_get_length(resp._32_4_);
      zmsg_append_u8((zmsg_t *)resp._32_4_,'\0');
      zmsg_append_u8((zmsg_t *)resp._32_4_,bStack_4c);
      uVar4 = zmsg_get_length(resp._32_4_);
      zmsg_append_u8((zmsg_t *)resp._32_4_,'\0');
      bVar2 = 0;
      while (puVar9 = (uint16_t *)
                      aps_group_table_next_by_endpoint(*(undefined1 *)((int)arg + 0x15),puVar9),
            puVar9 != (uint16_t *)0x0) {
        if (bStack_4c <= bVar8) {
          bVar2 = bVar2 + 1;
          zmsg_append_le16((zmsg_t *)resp._32_4_,*puVar9);
          zmsg_append_u8((zmsg_t *)resp._32_4_,'\0');
        }
        bVar8 = bVar8 + 1;
      }
      bStack_4b = bVar8;
      zmsg_write_bytes(resp._32_4_,uVar7,1,&bStack_4b);
      bStack_4b = bVar2;
      zmsg_write_bytes(resp._32_4_,uVar4,1,&bStack_4b);
      uVar7 = 0x41;
      goto _L0;
    }
_L0:
    uVar7 = 0x80;
_L0:
    iVar3 = zcl_packet_setup_default_response(&start_index,arg,uVar7);
  }
  else {
    if (*(char *)((int)arg + 0x20) != 'B') {
      uVar7 = 0x81;
      goto _L0;
    }
    uStack_4a = 0;
    bStack_4c = 0;
    uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_4a,&bStack_4c);
    bVar2 = bStack_4c;
    if (uVar5 < uStack_4a) goto _L0;
    iVar3 = 0;
    uVar1 = '\0';
    do {
      val_00 = uVar1;
      iVar3 = ezb_af_get_next_simple_desc(iVar3);
      uVar1 = val_00 + '\x01';
    } while (iVar3 != 0);
    zmsg_append_u8((zmsg_t *)resp._32_4_,val_00);
    bVar8 = 0;
    zmsg_append_u8((zmsg_t *)resp._32_4_,bVar2);
    zmsg_append_u8((zmsg_t *)resp._32_4_,'\0');
    bVar2 = 0;
    puVar6 = (uint8_t *)0x0;
    while (puVar6 = (uint8_t *)ezb_af_get_next_simple_desc(puVar6), uVar7 = resp._32_4_,
          puVar6 != (uint8_t *)0x0) {
      if (bStack_4c <= bVar8) {
        val = nwk_get_short_address();
        zmsg_append_le16((zmsg_t *)uVar7,val);
        bVar2 = bVar2 + 1;
        zmsg_append_u8((zmsg_t *)resp._32_4_,*puVar6);
        zmsg_append_le16((zmsg_t *)resp._32_4_,*(uint16_t *)(puVar6 + 2));
        zmsg_append_le16((zmsg_t *)resp._32_4_,*(uint16_t *)(puVar6 + 4));
        zmsg_append_u8((zmsg_t *)resp._32_4_,(byte)*(undefined2 *)(puVar6 + 6) & 0xf);
      }
      bVar8 = bVar8 + 1;
    }
    bStack_4b = bVar2;
    zmsg_write_bytes(resp._32_4_,2,1,&bStack_4b);
    uVar7 = 0x42;
_L0:
    iVar3 = zcl_packet_setup_response(&start_index,arg,uVar7);
  }
  if (iVar3 == 0) {
    zcl_packet_send(&start_index,0);
  }
  else {
    zcl_packet_free(&start_index);
  }
_L0:
  return (ezb_zcl_status_t)iVar3;
}

