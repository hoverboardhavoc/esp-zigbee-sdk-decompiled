/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_write_attr_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined2 uVar10;
  int iVar11;
  
  uVar10 = 0x104;
  iVar6 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar6 != 0) {
    uVar10 = *(undefined2 *)(iVar6 + 1);
  }
  iVar6 = 0;
  sVar3 = 0x98;
  while ((iVar6 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    iVar4 = iVar6 * 0xc;
    iVar6 = iVar6 + 1;
    iVar4 = *(int *)(param_1 + 0x14) + iVar4;
    sVar5 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar4 + 2),*(undefined4 *)(iVar4 + 8));
    sVar3 = sVar3 + sVar5;
  }
  iVar6 = zb_buf_get_func(0,sVar3);
  if (iVar6 != 0) {
    puVar8 = (undefined1 *)zb_buf_reuse_func();
    *puVar8 = 0;
    pcVar9 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar9;
    *pcVar9 = cVar2 + '\x01';
    puVar8[1] = cVar2;
    puVar8[2] = 2;
    puVar8 = puVar8 + 3;
    iVar4 = 0;
    while ((iVar4 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      iVar11 = iVar4 * 0xc;
      iVar4 = iVar4 + 1;
      puVar8 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar11))
      ;
      *puVar8 = (char)*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar11 + 2);
      iVar11 = *(int *)(param_1 + 0x14) + iVar11;
      puVar8 = (undefined1 *)
               zb_zcl_put_value_to_packet(*(undefined1 *)(iVar11 + 2),*(undefined4 *)(iVar11 + 8));
    }
    zb_zcl_finish_and_send_packet
              (iVar6,puVar8,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar10,*(undefined2 *)(param_1 + 0x10));
    pbVar7 = (byte *)zb_buf_begin_func(iVar6);
    if ((*pbVar7 >> 2 & 1) == 0) {
      iVar6 = 1;
    }
    else {
      iVar6 = 3;
    }
    return pbVar7[iVar6];
  }
  pbVar7 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar7;
  *pbVar7 = bVar1 + 1;
  return bVar1;
}

