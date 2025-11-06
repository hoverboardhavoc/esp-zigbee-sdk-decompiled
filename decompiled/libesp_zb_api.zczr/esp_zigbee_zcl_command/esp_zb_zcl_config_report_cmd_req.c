/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_config_report_cmd_req(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  undefined2 uVar8;
  int iVar9;
  
  uVar8 = 0x104;
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar8 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 != 0) {
    uVar7 = *(uint *)(param_1 + 0x10);
    puVar4 = (undefined1 *)
             zb_zcl_construct_general_command_header
                       (uVar7 >> 0x12 & 1,uVar7 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                        uVar7 >> 0x13 & 1,6);
    iVar9 = 0;
    while ((iVar9 < (int)(uint)*(ushort *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      piVar2 = (int *)(*(int *)(param_1 + 0x18) + iVar9 * 0x14);
      if (*piVar2 == 0) {
        *puVar4 = 0;
        puVar4 = (undefined1 *)zb_put_next_htole16((short)piVar2[1]);
        *puVar4 = (char)piVar2[2];
        zb_put_next_htole16(*(undefined2 *)((int)piVar2 + 10));
        puVar4 = (undefined1 *)zb_put_next_htole16((short)piVar2[3]);
        iVar5 = zb_zcl_is_analog_data_type((char)piVar2[2]);
        if (iVar5 != 0) {
          puVar4 = (undefined1 *)zb_zcl_put_value_to_packet(puVar4,(char)piVar2[2],piVar2[4]);
        }
      }
      else {
        *puVar4 = 1;
        zb_put_next_htole16(puVar4 + 1,(short)piVar2[1]);
        puVar4 = (undefined1 *)zb_put_next_htole16((short)piVar2[2]);
      }
      iVar9 = iVar9 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar3,puVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar8,*(undefined2 *)(param_1 + 0x10));
    pbVar6 = (byte *)zb_buf_begin_func(iVar3);
    return pbVar6[(-(uint)((*pbVar6 & 4) == 0) & 0xfffffffe) + 3];
  }
  pbVar6 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar6;
  *pbVar6 = bVar1 + 1;
  return bVar1;
}

