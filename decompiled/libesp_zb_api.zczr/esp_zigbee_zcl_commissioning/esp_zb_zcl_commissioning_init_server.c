/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zb_zcl_commissioning_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_commissioning_init_server(void)

{
  void *__src;
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  size_t __n;
  int iVar4;
  
  iVar3 = get_endpoint_by_cluster(0x15,1);
  if (iVar3 == 0) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
              ,0x309);
  }
  zb_af_get_endpoint_desc();
  iVar3 = get_cluster_desc(0x15,1);
  iVar4 = 0;
  do {
    if ((int)(uint)*(ushort *)(iVar3 + 2) <= iVar4) {
      zb_zcl_add_cluster_handlers
                (0x15,1,0,esp_zcl_comm_write_attr_hook,
                 esp_zcl_process_commissioning_srv_specific_commands);
      return;
    }
    puVar2 = (ushort *)(*(int *)(iVar3 + 4) + iVar4 * 10);
    __src = *(void **)(puVar2 + 3);
    __n = esp_zb_zcl_get_attribute_size((char)puVar2[1],__src);
    uVar1 = *puVar2;
    if (uVar1 == 0x15) {
_L0:
      *(undefined1 *)(puVar2 + 3) = 0xb0;
      *(undefined1 *)((int)puVar2 + 7) = 0xd;
      *(undefined1 *)(puVar2 + 4) = 1;
      *(undefined1 *)((int)puVar2 + 9) = 0;
    }
    else {
      if (uVar1 < 0x16) {
        if (((((uVar1 != 6) && (6 < uVar1)) && (uVar1 != 0x12)) &&
            ((uVar1 < 0x13 && (uVar1 != 0x10)))) && (uVar1 != 0x11)) goto _L0;
        goto _L0;
      }
      if (uVar1 == 0x23) goto _L0;
      if (uVar1 < 0x24) {
        if (((uVar1 != 0x20) && (uVar1 < 0x21)) && ((uVar1 != 0x16 && (uVar1 != 0x17)))) goto _L0;
        goto _L0;
      }
      if (uVar1 == 0x40) goto _L0;
      if (uVar1 < 0x41) {
        if ((uVar1 == 0x30) || (uVar1 == 0x31)) goto _L0;
      }
      else if ((uVar1 == 0x41) || (uVar1 == 0x42)) goto _L0;
    }
_L0:
    memcpy(*(void **)(puVar2 + 3),__src,__n);
    free(__src);
    iVar4 = iVar4 + 1;
  } while( true );
}

