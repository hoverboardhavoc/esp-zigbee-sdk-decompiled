/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
  int iVar10;
  int iVar11;
  
  iVar6 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar6 != 0) {
    iVar10 = 0;
    sVar3 = 0x98;
    while ((iVar10 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      iVar4 = iVar10 * 0xc;
      iVar10 = iVar10 + 1;
      iVar4 = *(int *)(param_1 + 0x14) + iVar4;
      sVar5 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar4 + 2),*(undefined4 *)(iVar4 + 8));
      sVar3 = sVar3 + sVar5;
    }
    iVar10 = zb_buf_get_func(0,sVar3);
    if (iVar10 != 0) {
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
        puVar8 = (undefined1 *)
                 zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar11));
        *puVar8 = (char)*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar11 + 2);
        iVar11 = *(int *)(param_1 + 0x14) + iVar11;
        puVar8 = (undefined1 *)
                 zb_zcl_put_value_to_packet(*(undefined1 *)(iVar11 + 2),*(undefined4 *)(iVar11 + 8))
        ;
      }
      zb_zcl_finish_and_send_packet
                (iVar10,puVar8,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar6 + 1),
                 *(undefined2 *)(param_1 + 0x10));
      pbVar7 = (byte *)zb_buf_begin_func(iVar10);
      if ((*pbVar7 >> 2 & 1) == 0) {
        iVar6 = 1;
      }
      else {
        iVar6 = 3;
      }
      return pbVar7[iVar6];
    }
  }
  pbVar7 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar7;
  *pbVar7 = bVar1 + 1;
  return bVar1;
}

