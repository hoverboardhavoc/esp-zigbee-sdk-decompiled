/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_config_report_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar4 != 0) && (iVar6 = zb_buf_get_out_func(), iVar6 != 0)) {
    if (**(int **)(param_1 + 0x14) == 0) {
      puVar7 = (undefined1 *)zb_buf_reuse_func();
      *puVar7 = 0;
    }
    else {
      puVar7 = (undefined1 *)zb_buf_reuse_func();
      *puVar7 = 8;
    }
    pcVar8 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar8;
    puVar3 = puVar7 + 3;
    iVar11 = 0;
    *pcVar8 = cVar2 + '\x01';
    puVar7[1] = cVar2;
    puVar7[2] = 6;
    while ((iVar11 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      *puVar3 = 0;
      iVar10 = iVar11 * 0x10;
      puVar7 = (undefined1 *)
               zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 4)
                                  );
      *puVar7 = *(undefined1 *)(*(int *)(param_1 + 0x14) + iVar10 + 6);
      zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 8));
      puVar3 = (undefined1 *)
               zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 10));
      iVar9 = zb_zcl_is_analog_data_type(*(undefined1 *)(*(int *)(param_1 + 0x14) + iVar10 + 6));
      if (iVar9 != 0) {
        iVar10 = *(int *)(param_1 + 0x14) + iVar10;
        puVar3 = (undefined1 *)
                 zb_zcl_put_value_to_packet
                           (puVar3,*(undefined1 *)(iVar10 + 6),*(undefined4 *)(iVar10 + 0xc));
      }
      iVar11 = iVar11 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar6,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar4 + 1),
               *(undefined2 *)(param_1 + 0x10));
    pbVar5 = (byte *)zb_buf_begin_func(iVar6);
    if ((*pbVar5 >> 2 & 1) == 0) {
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

