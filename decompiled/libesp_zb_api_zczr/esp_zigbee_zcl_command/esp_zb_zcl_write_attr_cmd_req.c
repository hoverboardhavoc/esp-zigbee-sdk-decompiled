/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_write_attr_cmd_req(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  
  uVar2 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar2 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = 0;
  sVar9 = 0x98;
  while ((iVar4 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
    iVar10 = iVar4 * 0xc;
    iVar4 = iVar4 + 1;
    iVar10 = *(int *)(param_1 + 0x18) + iVar10;
    sVar3 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar10 + 2),*(undefined4 *)(iVar10 + 8));
    sVar9 = sVar9 + sVar3;
  }
  iVar4 = zb_buf_get_func(0,sVar9);
  if (iVar4 != 0) {
    uVar8 = *(uint *)(param_1 + 0x10);
    uVar6 = zb_zcl_construct_general_command_header
                      (uVar8 >> 0x12 & 1,uVar8 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                       uVar8 >> 0x13 & 1,2);
    iVar10 = 0;
    while ((iVar10 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      iVar11 = iVar10 * 0xc;
      iVar10 = iVar10 + 1;
      puVar7 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar11))
      ;
      *puVar7 = (char)*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar11 + 2);
      iVar11 = *(int *)(param_1 + 0x18) + iVar11;
      uVar6 = zb_zcl_put_value_to_packet(*(undefined1 *)(iVar11 + 2),*(undefined4 *)(iVar11 + 8));
    }
    zb_zcl_finish_and_send_packet
              (iVar4,uVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar2,*(undefined2 *)(param_1 + 0x10));
    pbVar5 = (byte *)zb_buf_begin_func(iVar4);
    if ((*pbVar5 & 4) == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = 3;
    }
    return pbVar5[iVar4];
  }
  pbVar5 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar5;
  *pbVar5 = bVar1 + 1;
  return bVar1;
}

