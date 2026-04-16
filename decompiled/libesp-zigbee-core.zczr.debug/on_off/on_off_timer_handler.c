/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void on_off_timer_handler(void *arg)

{
  zcl_attr_desc_t *unaff_s1;
  zcl_attr_desc_t *pzVar1;
  undefined1 *puVar2;
  zcl_attr_desc_t *unaff_s2;
  zcl_attr_desc_t *unaff_s3;
  
  if (arg == (void *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x25f,
                  "on_off_timer_handler","arg != ((void *)0)");
_L0:
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x266,
                  "on_off_timer_handler","on_off_attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    unaff_s1 = on_off_srv_get_attr_desc(*arg,0);
                    /* WARNING: Load size is inaccurate */
    unaff_s2 = on_off_srv_get_attr_desc(*arg,0x4001);
                    /* WARNING: Load size is inaccurate */
    pzVar1 = on_off_srv_get_attr_desc(*arg,0x4002);
    if (unaff_s1 == (zcl_attr_desc_t *)0x0) goto _L0;
    if (unaff_s2 == (zcl_attr_desc_t *)0x0) {
      return;
    }
    if (pzVar1 == (zcl_attr_desc_t *)0x0) {
      return;
    }
                    /* WARNING: Load size is inaccurate */
    unaff_s1 = (zcl_attr_desc_t *)(uint)*unaff_s1->data_p;
                    /* WARNING: Load size is inaccurate */
    unaff_s3 = (zcl_attr_desc_t *)(uint)*unaff_s2->data_p;
                    /* WARNING: Load size is inaccurate */
    unaff_s2 = (zcl_attr_desc_t *)(uint)*pzVar1->data_p;
    if (unaff_s1 != (zcl_attr_desc_t *)0x0) {
      if (unaff_s3 == (zcl_attr_desc_t *)0x0) {
        unaff_s1 = (zcl_attr_desc_t *)0x0;
      }
      else {
        puVar2 = (undefined1 *)((int)&unaff_s3[-1].next + 3);
        unaff_s3 = (zcl_attr_desc_t *)((uint)puVar2 & 0xffff);
        if (((uint)puVar2 & 0xffff) == 0) {
          unaff_s1 = (zcl_attr_desc_t *)0x0;
        }
      }
      goto _L0;
    }
  }
  if (unaff_s2 != (zcl_attr_desc_t *)0x0) {
    unaff_s2 = (zcl_attr_desc_t *)((uint)((int)&unaff_s2[-1].next + 3) & 0xffff);
  }
_L0:
                    /* WARNING: Load size is inaccurate */
  on_off_process_transition(*arg,'B',(uint8_t)unaff_s1,(uint16_t)unaff_s3,(uint16_t)unaff_s2);
  if (unaff_s1 != (zcl_attr_desc_t *)0x0) {
    unaff_s2 = unaff_s3;
  }
  if (unaff_s2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    on_off_timer_start(*arg,100);
  }
  return;
}

