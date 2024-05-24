/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_report_config_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_read_report_config_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined1 *puVar9;
  int iVar10;
  
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar4 != 0) && (iVar6 = zb_buf_get_out_func(), iVar6 != 0)) {
    puVar7 = (undefined1 *)zb_buf_reuse_func();
    *puVar7 = 0;
    pcVar8 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar8;
    puVar9 = puVar7 + 3;
    *pcVar8 = cVar2 + '\x01';
    puVar7[1] = cVar2;
    puVar7[2] = 8;
    iVar3 = 0;
    while ((iVar3 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      iVar10 = iVar3 * 4;
      if (*(char *)(*(int *)(param_1 + 0x14) + iVar10) == '\0') {
        *puVar9 = 0;
      }
      else {
        *puVar9 = 1;
      }
      iVar3 = iVar3 + 1;
      puVar9 = (undefined1 *)
               zb_put_next_htole16(puVar9 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 2)
                                  );
    }
    zb_zcl_finish_and_send_packet
              (iVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
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

