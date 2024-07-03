/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
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
  int iVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  char cVar10;
  undefined4 unaff_s2;
  uint uVar11;
  
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
      unaff_s2 = zb_buf_get_out_func();
      pcVar4 = (char *)zb_buf_reuse_func();
      pcVar5 = pcVar4;
      if (*(short *)(uVar1 + 0x36) == -1) goto _L0;
      *pcVar4 = '\f';
      pcVar5 = (char *)zb_put_next_htole16(pcVar4 + 1,*(undefined2 *)(uVar1 + 0x36));
      pcVar4 = (char *)zb_zcl_get_ctx();
      cVar10 = *pcVar4;
      unaff_s1 = pcVar5 + 2;
      *pcVar4 = cVar10 + '\x01';
      *pcVar5 = cVar10;
      pcVar5[1] = '\n';
      do {
        iVar3 = zb_buf_get_ptr_off_func(unaff_s2,unaff_s1);
        iVar6 = zb_buf_len_func(unaff_s2);
        zb_buf_alloc_right_func(unaff_s2,iVar3 - iVar6);
        while( true ) {
          puVar7 = (undefined2 *)
                   zb_zcl_get_attr_desc_manuf_a
                             (*(undefined1 *)(uVar1 + 1),*(undefined2 *)(uVar1 + 2),
                              *(undefined1 *)(uVar1 + 4),*(undefined2 *)(uVar1 + 6),
                              *(undefined2 *)(uVar1 + 0x36));
          iVar3 = zb_zcl_can_cluster_be_fragmented
                            (*(undefined2 *)(uVar1 + 0x34),*(undefined2 *)(uVar1 + 2));
          if (iVar3 == 0) {
            iVar3 = zb_buf_get_ptr_off_func(unaff_s2,unaff_s1);
            uVar11 = 0x52 - iVar3;
          }
          else {
            iVar3 = zb_buf_get_max_size_func(unaff_s2);
            iVar6 = zb_buf_get_ptr_off_func(unaff_s2,unaff_s1);
            uVar11 = (iVar3 + -0x2d) - iVar6;
          }
          iVar3 = esp_zb_zcl_get_attribute_size
                            (*(undefined1 *)(puVar7 + 1),*(undefined4 *)(puVar7 + 3));
          if (iVar3 == 0xffff) goto _L0;
          if (iVar3 + 3U <= (uVar11 & 0xffff)) {
            zb_buf_alloc_right_func(unaff_s2);
            puVar8 = (undefined1 *)zb_put_next_htole16(*puVar7);
            *puVar8 = *(undefined1 *)(puVar7 + 1);
            unaff_s1 = (char *)esp_zb_zcl_put_attribute_value(*(undefined4 *)(puVar7 + 3),iVar3);
            goto _L0;
          }
          iVar3 = zb_zcl_can_cluster_be_fragmented
                            (*(undefined2 *)(uVar1 + 0x34),*(undefined2 *)(uVar1 + 2));
          if (iVar3 == 0) break;
          iVar3 = zb_buf_get_max_size_func(unaff_s2);
          uVar9 = zb_buf_get_func(0,iVar3 + 1);
          zb_buf_copy_func(unaff_s2);
          zb_buf_free_func(unaff_s2);
          unaff_s2 = uVar9;
        }
        uVar9 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar9,"ESP_ZIGBEE_COMMAND");
_L0:
        zb_zcl_finish_and_send_packet
                  (unaff_s2,unaff_s1,param_1,*(undefined1 *)(param_1 + 0xc),
                   *(undefined1 *)(param_1 + 8),*(undefined1 *)(uVar1 + 1),
                   *(undefined2 *)(uVar1 + 0x34),*(undefined2 *)(uVar1 + 2));
_L0:
        if (uVar1 < *(int *)(iVar2 + 0x1b) + (uint)*(byte *)(iVar2 + 0x1a) * 0x38) {
          return 0;
        }
        pcVar4 = (char *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                                   ,0x145);
        pcVar5 = unaff_s1;
_L0:
        *pcVar4 = '\b';
        pcVar4 = (char *)zb_zcl_get_ctx();
        cVar10 = *pcVar4;
        unaff_s1 = pcVar5 + 3;
        *pcVar4 = cVar10 + '\x01';
        pcVar5[1] = cVar10;
        pcVar5[2] = '\n';
      } while( true );
    }
    uVar9 = 0x106;
  }
  return uVar9;
}

