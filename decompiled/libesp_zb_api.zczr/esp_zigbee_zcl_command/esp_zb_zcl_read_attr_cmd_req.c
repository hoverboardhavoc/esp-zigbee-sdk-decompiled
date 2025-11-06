/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_read_attr_cmd_req(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar2 = 0x104;
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar2 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 == 0) {
    pbVar5 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + 1;
    return bVar1;
  }
  uVar6 = *(uint *)(param_1 + 0x10);
  uVar4 = zb_zcl_construct_general_command_header
                    (uVar6 >> 0x12 & 1,uVar6 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                     uVar6 >> 0x13 & 1,0);
  iVar8 = 0;
  while ((iVar8 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
    iVar7 = iVar8 * 2;
    iVar8 = iVar8 + 1;
    uVar4 = zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar7));
  }
  zb_zcl_finish_and_send_packet
            (iVar3,uVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar2,*(undefined2 *)(param_1 + 0x10));
  pbVar5 = (byte *)zb_buf_begin_func(iVar3);
  return pbVar5[(-(uint)((*pbVar5 & 4) == 0) & 0xfffffffe) + 3];
}

