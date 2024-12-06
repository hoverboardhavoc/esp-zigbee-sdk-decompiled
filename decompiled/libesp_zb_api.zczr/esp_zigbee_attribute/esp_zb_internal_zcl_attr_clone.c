/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_internal_zcl_attr_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_internal_zcl_attr_clone(void *param_1,void *param_2)

{
  void *__dest;
  size_t __size;
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    return 0x102;
  }
  uVar1 = 0x102;
  if (param_2 != (void *)0x0) {
    memcpy(param_1,param_2,10);
    if ((*(byte *)((int)param_2 + 3) & 0x40) == 0) {
      __size = esp_zb_zcl_get_attribute_size
                         (*(undefined1 *)((int)param_2 + 2),*(undefined4 *)((int)param_2 + 6));
    }
    else {
      __size = (size_t)*(byte *)((int)param_2 + 2);
    }
    if (__size == 0) {
      *(undefined1 *)((int)param_1 + 6) = 0;
      *(undefined1 *)((int)param_1 + 7) = 0;
      *(undefined1 *)((int)param_1 + 8) = 0;
      *(undefined1 *)((int)param_1 + 9) = 0;
    }
    else {
      __dest = malloc(__size);
      *(char *)((int)param_1 + 7) = (char)((uint)__dest >> 8);
      *(char *)((int)param_1 + 8) = (char)((uint)__dest >> 0x10);
      *(char *)((int)param_1 + 9) = (char)((uint)__dest >> 0x18);
      *(char *)((int)param_1 + 6) = (char)__dest;
      if (__dest == (void *)0x0) {
        return 0x101;
      }
      if ((*(byte *)((int)param_2 + 3) & 0x40) == 0) {
        esp_zb_zcl_put_attribute_value
                  (*(undefined1 *)((int)param_2 + 2),*(void **)((int)param_2 + 6));
      }
      else {
        memcpy(__dest,*(void **)((int)param_2 + 6),__size);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

