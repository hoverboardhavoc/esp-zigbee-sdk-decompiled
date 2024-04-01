/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_report_attr_cmd_req(undefined2 *param_1)

{
  char cVar1;
  bool bVar2;
  byte *pbVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  char *pcVar12;
  char *pcVar13;
  undefined2 *puVar14;
  int iVar15;
  undefined1 *puVar16;
  byte *pbVar17;
  uint uVar18;
  byte bVar19;
  uint uVar20;
  
  iVar5 = zb_af_get_endpoint_desc(*(undefined1 *)((int)param_1 + 9));
  if (((iVar5 == 0) ||
      (iVar5 = zb_zcl_get_attr_desc_manuf_a
                         (*(undefined1 *)((int)param_1 + 9),param_1[8],*(undefined1 *)(param_1 + 9),
                          param_1[10],0xffff), iVar5 == 0)) || ((*(byte *)(iVar5 + 3) & 4) == 0)) {
    uVar6 = 0x106;
  }
  else {
    iVar7 = zb_zcl_get_ctx();
    uVar20 = 0;
    if (*(int *)(iVar7 + 4) != 0) {
_L0:
      iVar7 = zb_zcl_get_ctx();
      if (uVar20 < **(byte **)(iVar7 + 4)) {
        iVar8 = zb_zcl_get_ctx();
        iVar7 = uVar20 * 4;
        if (*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 1) + iVar7) + 0x1b) != 0) {
          iVar8 = zb_zcl_get_ctx();
          iVar8 = *(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 1) + iVar7) + 0x1b);
          for (bVar19 = 0; iVar9 = zb_zcl_get_ctx(),
              bVar19 < *(byte *)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 1) + iVar7) + 0x1a);
              bVar19 = bVar19 + 1) {
            if ((*(short *)(iVar8 + 2) == param_1[8]) && (*(short *)(iVar8 + 6) == param_1[10])) {
              *(byte *)(iVar8 + 8) = *(byte *)(iVar8 + 8) & 0xf7 | 6;
              *(undefined2 *)(iVar8 + 0x30) = *param_1;
              *(undefined1 *)(iVar8 + 0x32) = *(undefined1 *)(param_1 + 4);
              *(undefined1 *)(iVar8 + 1) = *(undefined1 *)((int)param_1 + 9);
              iVar9 = zb_zcl_get_ctx();
              *(undefined2 *)(iVar8 + 0x34) =
                   *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 1) + iVar7) + 1);
              iVar9 = zb_zcl_get_ctx();
              if (*(char *)(iVar9 + 0xaa) != '\0') {
                iVar7 = zb_zcl_can_cluster_be_fragmented
                                  (*(undefined2 *)(iVar8 + 0x34),*(undefined2 *)(iVar8 + 2));
                if (iVar7 == 0) {
                  iVar7 = zb_zcl_get_ctx();
                  uVar4 = *(undefined1 *)(iVar7 + 0xaa);
                  iVar7 = zb_zcl_get_ctx();
                  uVar6 = zb_buf_reuse_func(*(undefined1 *)(iVar7 + 0xaa));
                  iVar9 = zb_buf_get_ptr_off_func(uVar4,uVar6);
                  iVar7 = 0x52;
                }
                else {
                  iVar7 = zb_zcl_get_ctx();
                  iVar7 = zb_buf_get_max_size_func(*(undefined1 *)(iVar7 + 0xaa));
                  iVar9 = zb_zcl_get_ctx();
                  uVar4 = *(undefined1 *)(iVar9 + 0xaa);
                  iVar9 = zb_zcl_get_ctx();
                  iVar7 = iVar7 + -0x2d;
                  uVar6 = zb_buf_reuse_func(*(undefined1 *)(iVar9 + 0xaa));
                  iVar9 = zb_buf_get_ptr_off_func(uVar4,uVar6);
                }
                uVar10 = zb_zcl_get_attribute_size
                                   (*(undefined1 *)(iVar5 + 2),*(undefined4 *)(iVar5 + 6));
                if ((iVar7 - iVar9 & 0xffffU) < uVar10) {
                  iVar7 = zb_zcl_get_ctx();
                  zb_buf_free_func(*(undefined1 *)(iVar7 + 0xaa));
                  iVar7 = zb_zcl_get_ctx();
                  uVar4 = zb_buf_get_func(0,uVar10 + 0x46);
                  *(undefined1 *)(iVar7 + 0xaa) = uVar4;
                }
                uVar6 = zb_buf_get_out_func();
                uVar10 = *(uint *)(param_1 + 6);
                iVar7 = zb_zcl_get_attr_desc_manuf_a
                                  (*(undefined1 *)(iVar8 + 1),*(undefined2 *)(iVar8 + 2),
                                   *(undefined1 *)(iVar8 + 4),*(undefined2 *)(iVar8 + 6),
                                   *(undefined2 *)(iVar8 + 0x36));
                pbVar11 = (byte *)zb_buf_reuse_func(uVar6);
                bVar19 = *(byte *)(iVar7 + 3);
                bVar2 = (bVar19 & 0x20) != 0;
                *pbVar11 = bVar2 << 2 | 8;
                iVar7 = iVar8;
                if ((bVar19 & 0x20) == 0) {
                  pbVar17 = (byte *)zb_zcl_get_ctx();
                  bVar19 = *pbVar17;
                  pbVar3 = pbVar11 + 3;
                  *pbVar17 = bVar19 + 1;
                  pbVar11[1] = bVar19;
                  pbVar11[2] = 10;
                }
                else {
                  pcVar12 = (char *)zb_put_next_htole16(pbVar11 + 1,*(undefined2 *)(iVar8 + 0x36));
                  pcVar13 = (char *)zb_zcl_get_ctx();
                  cVar1 = *pcVar13;
                  pbVar3 = (byte *)(pcVar12 + 2);
                  *pcVar13 = cVar1 + '\x01';
                  *pcVar12 = cVar1;
                  pcVar12[1] = '\n';
                }
                goto _L0;
              }
            }
            iVar8 = iVar8 + 0x38;
          }
        }
        goto _L0;
      }
    }
    uVar6 = 0;
  }
  return uVar6;
  while( true ) {
    puVar16 = (undefined1 *)zb_put_next_htole16(pbVar3,*puVar14);
    *puVar16 = *(undefined1 *)(puVar14 + 1);
    pbVar3 = (byte *)esp_zb_zcl_put_attribute_value(*(undefined4 *)(puVar14 + 3),iVar9);
    zb_zcl_save_reported_value(iVar7,puVar14);
    *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) & 0xe9 | 0x20;
    iVar7 = zb_zcl_get_next_reporting_info(iVar8,bVar2);
    if (iVar7 == 0) break;
_L0:
    puVar14 = (undefined2 *)
              zb_zcl_get_attr_desc_manuf_a
                        (*(undefined1 *)(iVar7 + 1),*(undefined2 *)(iVar7 + 2),
                         *(undefined1 *)(iVar7 + 4),*(undefined2 *)(iVar7 + 6),
                         *(undefined2 *)(iVar7 + 0x36));
    iVar9 = zb_zcl_can_cluster_be_fragmented
                      (*(undefined2 *)(iVar7 + 0x34),*(undefined2 *)(iVar7 + 2));
    if (iVar9 == 0) {
      iVar9 = zb_buf_get_ptr_off_func(uVar6,pbVar3);
      uVar18 = 0x52 - iVar9;
    }
    else {
      iVar9 = zb_buf_get_max_size_func(uVar6);
      iVar15 = zb_buf_get_ptr_off_func(uVar6,pbVar3);
      uVar18 = (iVar9 + -0x2d) - iVar15;
    }
    iVar9 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar14 + 1),*(undefined4 *)(puVar14 + 3))
    ;
    if (iVar9 == 0xffff) goto _L0;
    if ((uVar18 & 0xffff) < iVar9 + 3U) break;
  }
  zb_zcl_finish_and_send_packet
            (uVar6,pbVar3,iVar8 + 0x30,uVar10 & 0xff,*(undefined1 *)(iVar8 + 0x32),
             *(undefined1 *)(iVar8 + 1),*(undefined2 *)(iVar8 + 0x34),*(undefined2 *)(iVar8 + 2));
_L0:
  uVar20 = uVar20 + 1 & 0xff;
  goto _L0;
}

