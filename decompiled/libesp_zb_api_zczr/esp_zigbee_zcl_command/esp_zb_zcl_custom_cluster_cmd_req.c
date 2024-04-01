/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  
  uVar2 = esp_zb_zcl_get_attribute_size
                    (*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
  if (((uVar2 != 0xffff) || (uVar2 = (uint)*(ushort *)(param_1 + 0x20), uVar2 != 0xffff)) &&
     (iVar4 = zb_buf_get_func(0,uVar2 + 0x1a), iVar4 != 0)) {
    pbVar3 = (byte *)zb_buf_reuse_func();
    *pbVar3 = (byte)(*(int *)(param_1 + 0x18) << 3) | 1;
    pbVar5 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + 1;
    pbVar3[1] = bVar1;
    pbVar3[2] = (byte)*(undefined2 *)(param_1 + 0x14);
    uVar6 = esp_zb_zcl_put_attribute_value
                      (pbVar3 + 3,*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                       uVar2);
    zb_zcl_finish_and_send_packet
              (iVar4,uVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
               *(undefined2 *)(param_1 + 0x12));
    pbVar3 = (byte *)zb_buf_begin_func(iVar4);
    if ((*pbVar3 >> 2 & 1) == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = 3;
    }
    return pbVar3[iVar4];
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + 1;
  return bVar1;
}

