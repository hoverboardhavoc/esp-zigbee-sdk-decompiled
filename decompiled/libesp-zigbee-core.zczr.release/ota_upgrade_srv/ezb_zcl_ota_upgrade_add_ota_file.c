/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_add_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_ota_file_handle_t
ezb_zcl_ota_upgrade_add_ota_file(uint8_t ep_id,void *image,uint32_t image_size)

{
  ushort uVar1;
  ota_upgrade_file_t *__dest;
  int iVar2;
  undefined1 *puVar3;
  ota_upgrade_file_table_t *poVar4;
  void *__src;
  uint uVar5;
  
  if ((image == (void *)0x0) ||
     (poVar4 = ota_upgrade_get_file_table(ep_id), poVar4 == (ota_upgrade_file_table_t *)0x0)) {
_L0:
    __dest = (ota_upgrade_file_t *)0x0;
  }
  else {
    uVar5 = 0;
    do {
      if ((uint)poVar4->size <= (uVar5 & 0xff)) goto _L0;
      __dest = poVar4->entry + uVar5;
      uVar5 = uVar5 + 1;
    } while ((__dest->header).total_image_size != 0);
    memcpy(__dest,image,0x38);
    uVar1 = (__dest->header).hdr_fc;
    iVar2 = 0x38;
    if ((uVar1 & 1) != 0) {
      iVar2 = 0x39;
      (__dest->optional).security_credential_version = *(uint8_t *)((int)image + 0x38);
    }
    if ((uVar1 & 2) != 0) {
      __src = (void *)((int)image + iVar2);
      iVar2 = iVar2 + 8;
      memcpy(&(__dest->optional).upgrade_file_destination,__src,8);
    }
    if ((uVar1 & 4) != 0) {
      *(undefined1 *)&(__dest->optional).minimum_hardware_version =
           *(undefined1 *)((int)image + iVar2);
      puVar3 = (undefined1 *)(iVar2 + 2 + (int)image);
      *(undefined1 *)((int)&(__dest->optional).minimum_hardware_version + 1) =
           ((undefined1 *)((int)image + iVar2))[1];
      *(undefined1 *)&(__dest->optional).maximum_hardware_version = *puVar3;
      *(undefined1 *)((int)&(__dest->optional).maximum_hardware_version + 1) = puVar3[1];
    }
    if ((__dest->header).total_image_size == image_size) {
      __dest->data = (uint8_t *)image;
    }
    else {
      (__dest->header).total_image_size = 0;
    }
  }
  return __dest;
}

