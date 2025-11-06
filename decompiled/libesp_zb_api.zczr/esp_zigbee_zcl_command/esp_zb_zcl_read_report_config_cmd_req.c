/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_report_config_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_read_report_config_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar2 != 0) && (iVar4 = zb_buf_get_out_func(), iVar4 != 0)) {
    uVar6 = *(uint *)(param_1 + 0x10);
    puVar5 = (undefined1 *)
             zb_zcl_construct_general_command_header
                       (uVar6 >> 0x12 & 1,uVar6 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                        uVar6 >> 0x13 & 1,8);
    iVar8 = 0;
    while ((iVar8 < (int)(uint)*(ushort *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      iVar7 = iVar8 * 4;
      if (*(char *)(*(int *)(param_1 + 0x18) + iVar7) == '\0') {
        *puVar5 = 0;
      }
      else {
        *puVar5 = 1;
      }
      iVar8 = iVar8 + 1;
      puVar5 = (undefined1 *)
               zb_put_next_htole16(puVar5 + 1,*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar7 + 2))
      ;
    }
    zb_zcl_finish_and_send_packet
              (iVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar2 + 1),
               *(undefined2 *)(param_1 + 0x10));
    pbVar3 = (byte *)zb_buf_begin_func(iVar4);
    return pbVar3[(-(uint)((*pbVar3 & 4) == 0) & 0xfffffffe) + 3];
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + 1;
  return bVar1;
}

