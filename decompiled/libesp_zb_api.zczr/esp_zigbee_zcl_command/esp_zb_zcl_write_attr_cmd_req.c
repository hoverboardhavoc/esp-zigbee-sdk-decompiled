/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_write_attr_cmd_req(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar2 = 0x104;
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar2 = *(undefined2 *)(iVar3 + 1);
  }
  iVar8 = 0;
  iVar3 = 0;
  while ((iVar8 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
    iVar9 = *(int *)(param_1 + 0x18) + iVar8 * 0xc;
    iVar9 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar9 + 2),*(undefined4 *)(iVar9 + 8));
    if (iVar9 == 0xffff) goto _L0;
    iVar3 = iVar3 + 3 + iVar9;
    iVar8 = iVar8 + 1;
  }
  iVar8 = 0x5c;
  if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
    iVar8 = 0x5a;
  }
  iVar3 = zb_buf_get_func(0,iVar8 + iVar3);
  if (iVar3 != 0) {
    uVar7 = *(uint *)(param_1 + 0x10);
    uVar4 = zb_zcl_construct_general_command_header
                      (uVar7 >> 0x12 & 1,uVar7 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                       uVar7 >> 0x13 & 1,2);
    iVar8 = 0;
    while ((iVar8 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      iVar9 = iVar8 * 0xc;
      iVar8 = iVar8 + 1;
      puVar6 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar9));
      *puVar6 = (char)*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar9 + 2);
      iVar9 = *(int *)(param_1 + 0x18) + iVar9;
      uVar4 = zb_zcl_put_value_to_packet(*(undefined1 *)(iVar9 + 2),*(undefined4 *)(iVar9 + 8));
    }
    zb_zcl_finish_and_send_packet
              (iVar3,uVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar2,*(undefined2 *)(param_1 + 0x10));
    pbVar5 = (byte *)zb_buf_begin_func(iVar3);
    if ((*pbVar5 & 4) == 0) {
      iVar3 = 1;
    }
    else {
      iVar3 = 3;
    }
    return pbVar5[iVar3];
  }
_L0:
  pbVar5 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar5;
  *pbVar5 = bVar1 + 1;
  return bVar1;
}

