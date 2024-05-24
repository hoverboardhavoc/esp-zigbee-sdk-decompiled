/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_report_attr_cmd_req(int param_1)

{
  uint uVar1;
  char *unaff_s1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  char cVar10;
  uint uVar11;
  undefined4 unaff_s6;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar2 == 0) ||
     (iVar3 = zb_zcl_get_attr_desc_manuf_a
                        (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
                         *(undefined1 *)(param_1 + 0x12),*(undefined2 *)(param_1 + 0x14),0xffff),
     iVar3 == 0)) {
    uVar9 = 0x105;
  }
  else {
    if (((*(byte *)(iVar3 + 3) & 4) != 0) && (9 < (byte)(*(char *)(iVar3 + 2) + 0xb8U))) {
      uVar1 = *(uint *)(iVar2 + 0x1b);
      cVar10 = '\0';
      while( true ) {
        if (*(char *)(iVar2 + 0x1a) == cVar10) goto _L0;
        if ((*(short *)(uVar1 + 2) == *(short *)(param_1 + 0x10)) &&
           (*(short *)(uVar1 + 6) == *(short *)(param_1 + 0x14))) break;
        cVar10 = cVar10 + '\x01';
        uVar1 = uVar1 + 0x38;
      }
      unaff_s6 = zb_buf_get_out_func();
      unaff_s1 = (char *)zb_buf_reuse_func();
      pcVar4 = unaff_s1;
      if (*(short *)(uVar1 + 0x36) == -1) goto _L0;
      *unaff_s1 = '\f';
      pcVar4 = (char *)zb_put_next_htole16(unaff_s1 + 1,*(undefined2 *)(uVar1 + 0x36));
      pcVar5 = (char *)zb_zcl_get_ctx();
      cVar10 = *pcVar5;
      *pcVar5 = cVar10 + '\x01';
      *pcVar4 = cVar10;
      pcVar4[1] = '\n';
      unaff_s1 = pcVar4 + 2;
      do {
        while( true ) {
          puVar6 = (undefined2 *)
                   zb_zcl_get_attr_desc_manuf_a
                             (*(undefined1 *)(uVar1 + 1),*(undefined2 *)(uVar1 + 2),
                              *(undefined1 *)(uVar1 + 4),*(undefined2 *)(uVar1 + 6),
                              *(undefined2 *)(uVar1 + 0x36));
          iVar3 = zb_zcl_can_cluster_be_fragmented
                            (*(undefined2 *)(uVar1 + 0x34),*(undefined2 *)(uVar1 + 2));
          if (iVar3 == 0) {
            iVar3 = zb_buf_get_ptr_off_func(unaff_s6,unaff_s1);
            uVar11 = 0x52 - iVar3;
          }
          else {
            iVar3 = zb_buf_get_max_size_func(unaff_s6);
            iVar7 = zb_buf_get_ptr_off_func(unaff_s6,unaff_s1);
            uVar11 = (iVar3 + -0x2d) - iVar7;
          }
          iVar3 = esp_zb_zcl_get_attribute_size
                            (*(undefined1 *)(puVar6 + 1),*(undefined4 *)(puVar6 + 3));
          if (iVar3 != 0xffff) break;
_L0:
          if (uVar1 < *(int *)(iVar2 + 0x1b) + (uint)*(byte *)(iVar2 + 0x1a) * 0x38) {
            return 0;
          }
          pcVar4 = (char *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                                     ,0x141);
_L0:
          *pcVar4 = '\b';
          pcVar4 = (char *)zb_zcl_get_ctx();
          cVar10 = *pcVar4;
          *pcVar4 = cVar10 + '\x01';
          unaff_s1[1] = cVar10;
          unaff_s1[2] = '\n';
          unaff_s1 = unaff_s1 + 3;
        }
        if (iVar3 + 3U <= (uVar11 & 0xffff)) {
          puVar8 = (undefined1 *)zb_put_next_htole16(unaff_s1,*puVar6);
          *puVar8 = *(undefined1 *)(puVar6 + 1);
          unaff_s1 = (char *)esp_zb_zcl_put_attribute_value(*(undefined4 *)(puVar6 + 3),iVar3);
_L0:
          zb_zcl_finish_and_send_packet
                    (unaff_s6,unaff_s1,param_1,*(undefined1 *)(param_1 + 0xc),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)(uVar1 + 1),
                     *(undefined2 *)(uVar1 + 0x34),*(undefined2 *)(uVar1 + 2));
          goto _L0;
        }
        iVar3 = zb_zcl_can_cluster_be_fragmented
                          (*(undefined2 *)(uVar1 + 0x34),*(undefined2 *)(uVar1 + 2));
        if (iVar3 == 0) {
          uVar9 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar9,"ESP_ZIGBEE_COMMAND");
          goto _L0;
        }
        iVar3 = zb_buf_get_max_size_func(unaff_s6);
        uVar9 = zb_buf_get_func(0,iVar3 + 1);
        zb_buf_copy_func(unaff_s6);
        zb_buf_free_func(unaff_s6);
        unaff_s6 = uVar9;
      } while( true );
    }
    uVar9 = 0x106;
  }
  return uVar9;
}

