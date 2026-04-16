/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_add_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_ota_file_handle_t
ezb_zcl_ota_upgrade_add_ota_file(uint8_t ep_id,void *image,uint32_t image_size)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  ushort uVar8;
  ota_upgrade_file_table_t *file_table;
  ota_upgrade_file_t *__dest;
  uint8_t *puVar9;
  int iVar10;
  undefined1 *puVar11;
  
  if (image == (void *)0x0) {
    __dest = (ota_upgrade_file_t *)0x0;
  }
  else {
    file_table = ota_upgrade_get_file_table(ep_id);
    __dest = ota_upgrade_file_table_get_empty_entry(file_table);
    if (__dest != (ota_upgrade_file_t *)0x0) {
      memcpy(__dest,image,0x38);
      uVar8 = (__dest->header).hdr_fc;
      if ((uVar8 & 1) == 0) {
        iVar10 = 0x38;
      }
      else {
        (__dest->optional).security_credential_version = *(uint8_t *)((int)image + 0x38);
        iVar10 = 0x39;
      }
      if ((uVar8 & 2) != 0) {
        puVar9 = (uint8_t *)((int)image + iVar10);
        uVar1 = puVar9[1];
        uVar2 = puVar9[2];
        uVar3 = puVar9[3];
        uVar4 = puVar9[4];
        uVar5 = puVar9[5];
        uVar6 = puVar9[6];
        uVar7 = puVar9[7];
        (__dest->optional).upgrade_file_destination.field_0.u8[0] = *puVar9;
        (__dest->optional).upgrade_file_destination.field_0.u8[1] = uVar1;
        (__dest->optional).upgrade_file_destination.field_0.u8[2] = uVar2;
        (__dest->optional).upgrade_file_destination.field_0.u8[3] = uVar3;
        (__dest->optional).upgrade_file_destination.field_0.u8[4] = uVar4;
        (__dest->optional).upgrade_file_destination.field_0.u8[5] = uVar5;
        (__dest->optional).upgrade_file_destination.field_0.u8[6] = uVar6;
        (__dest->optional).upgrade_file_destination.field_0.u8[7] = uVar7;
        iVar10 = iVar10 + 8;
      }
      if ((uVar8 & 4) != 0) {
        *(undefined1 *)&(__dest->optional).minimum_hardware_version =
             *(undefined1 *)((int)image + iVar10);
        *(undefined1 *)((int)&(__dest->optional).minimum_hardware_version + 1) =
             ((undefined1 *)((int)image + iVar10))[1];
        puVar11 = (undefined1 *)(iVar10 + 2 + (int)image);
        *(undefined1 *)&(__dest->optional).maximum_hardware_version = *puVar11;
        *(undefined1 *)((int)&(__dest->optional).maximum_hardware_version + 1) = puVar11[1];
      }
      if ((__dest->header).total_image_size == image_size) {
        __dest->data = (uint8_t *)image;
      }
      else {
        (__dest->header).total_image_size = 0;
      }
    }
  }
  return __dest;
}

