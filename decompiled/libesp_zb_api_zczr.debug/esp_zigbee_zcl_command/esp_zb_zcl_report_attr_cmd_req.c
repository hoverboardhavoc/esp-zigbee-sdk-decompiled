/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_report_attr_cmd_req(undefined2 *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  iVar5 = zb_af_get_endpoint_desc(*(undefined1 *)((int)param_1 + 9));
  if (iVar5 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar8,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_report_attr_cmd_req",0x11f,*(undefined1 *)((int)param_1 + 9));
    uVar8 = 0x106;
  }
  else {
    iVar5 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)((int)param_1 + 9),param_1[8],*(undefined1 *)(param_1 + 9),
                       param_1[10],0xffff);
    if (iVar5 == 0) {
      uVar8 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar8,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0x125,param_1[10]);
      uVar8 = 0x106;
    }
    else if ((*(byte *)(iVar5 + 3) & 4) == 0) {
      uVar8 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC8,uVar8,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0x126,param_1[10]);
      uVar8 = 0x106;
    }
    else {
      iVar6 = zb_zcl_get_ctx();
      if (*(int *)(iVar6 + 4) == 0) {
        uVar8 = 0;
      }
      else {
        uVar11 = 0;
        while( true ) {
          iVar6 = zb_zcl_get_ctx();
          if (**(byte **)(iVar6 + 4) <= uVar11) break;
          iVar6 = zb_zcl_get_ctx();
          iVar10 = uVar11 * 4;
          if (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 1) + iVar10) + 0x1b) != 0) {
            iVar6 = zb_zcl_get_ctx();
            iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 1) + iVar10) + 0x1b);
            bVar2 = 0;
            while( true ) {
              iVar7 = zb_zcl_get_ctx();
              if (*(byte *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 1) + iVar10) + 0x1a) <= bVar2)
              break;
              if ((*(short *)(iVar6 + 2) == param_1[8]) && (*(short *)(iVar6 + 6) == param_1[10])) {
                bVar1 = *(byte *)(iVar6 + 8);
                *(byte *)(iVar6 + 8) = bVar1 | 2;
                *(byte *)(iVar6 + 8) = bVar1 | 6;
                *(byte *)(iVar6 + 8) = bVar1 & 0xf7 | 6;
                *(undefined2 *)(iVar6 + 0x30) = *param_1;
                *(undefined1 *)(iVar6 + 0x32) = *(undefined1 *)(param_1 + 4);
                *(undefined1 *)(iVar6 + 1) = *(undefined1 *)((int)param_1 + 9);
                iVar7 = zb_zcl_get_ctx();
                *(undefined2 *)(iVar6 + 0x34) =
                     *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 1) + iVar10) + 1);
                iVar7 = zb_zcl_get_ctx();
                if (*(char *)(iVar7 + 0xaa) != '\0') {
                  iVar10 = zb_zcl_can_cluster_be_fragmented
                                     (*(undefined2 *)(iVar6 + 0x34),*(undefined2 *)(iVar6 + 2));
                  if (iVar10 == 0) {
                    iVar10 = zb_zcl_get_ctx();
                    uVar4 = *(undefined1 *)(iVar10 + 0xaa);
                    iVar10 = zb_zcl_get_ctx();
                    uVar8 = zb_buf_reuse_func(*(undefined1 *)(iVar10 + 0xaa));
                    uVar3 = zb_buf_get_ptr_off_func(uVar4,uVar8);
                    uVar3 = 0x52 - (uVar3 & 0xffff);
                  }
                  else {
                    iVar10 = zb_zcl_get_ctx();
                    iVar10 = zb_buf_get_max_size_func(*(undefined1 *)(iVar10 + 0xaa));
                    iVar7 = zb_zcl_get_ctx();
                    uVar4 = *(undefined1 *)(iVar7 + 0xaa);
                    iVar7 = zb_zcl_get_ctx();
                    uVar8 = zb_buf_reuse_func(*(undefined1 *)(iVar7 + 0xaa));
                    iVar7 = zb_buf_get_ptr_off_func(uVar4,uVar8);
                    uVar3 = (iVar10 - iVar7 & 0xffffU) - 0x2d;
                  }
                  uVar9 = zb_zcl_get_attribute_size
                                    (*(undefined1 *)(iVar5 + 2),*(undefined4 *)(iVar5 + 6));
                  if ((uVar3 & 0xffff) < uVar9) {
                    iVar10 = zb_zcl_get_ctx();
                    zb_buf_free_func(*(undefined1 *)(iVar10 + 0xaa));
                    iVar10 = zb_zcl_get_ctx();
                    uVar4 = zb_buf_get_func(0,uVar9 + 0x46);
                    *(undefined1 *)(iVar10 + 0xaa) = uVar4;
                  }
                  uVar8 = zb_buf_get_out_func();
                  esp_zb_zcl_send_report_attr_command(iVar6,uVar8,*(undefined4 *)(param_1 + 6));
                  break;
                }
              }
              iVar6 = iVar6 + 0x38;
              bVar2 = bVar2 + 1;
            }
          }
          uVar11 = uVar11 + 1 & 0xff;
        }
        uVar8 = 0;
      }
    }
  }
  return uVar8;
}

