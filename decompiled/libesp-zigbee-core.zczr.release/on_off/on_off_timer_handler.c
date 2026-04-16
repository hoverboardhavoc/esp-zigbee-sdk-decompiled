/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void on_off_timer_handler(void *arg)

{
  uint8_t ep_id;
  uint16_t x;
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint16_t attr_id;
  uint16_t y;
  byte on_off;
  
  if (arg != (void *)0x0) goto _L98;
  do {
    arg = (void *)__assert_func(0,0,0,0);
_L98:
                    /* WARNING: Load size is inaccurate */
    pzVar1 = on_off_srv_get_attr_desc(*arg,0);
                    /* WARNING: Load size is inaccurate */
    pzVar2 = on_off_srv_get_attr_desc(*arg,0x4001);
                    /* WARNING: Load size is inaccurate */
    pzVar3 = on_off_srv_get_attr_desc(*arg,0x4002);
  } while (pzVar1 == (zcl_attr_desc_t *)0x0);
  if ((pzVar2 != (zcl_attr_desc_t *)0x0) && (pzVar3 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    y = *pzVar3->data_p;
                    /* WARNING: Load size is inaccurate */
    x = *pzVar2->data_p;
    if (*pzVar1->data_p == 0) {
      on_off = 0;
      if (y != 0) {
        y = y - 1;
      }
    }
    else if (x == 0) {
      on_off = 0;
    }
    else {
      x = x - 1;
      on_off = *pzVar1->data_p & -(x != 0);
    }
                    /* WARNING: Load size is inaccurate */
    on_off_process_transition(*arg,'B',on_off,x,y);
    if (on_off != 0) {
      y = x;
    }
    if (y != 0) {
                    /* WARNING: Load size is inaccurate */
      ep_id = *arg;
      pzVar1 = on_off_srv_get_attr_desc(ep_id,attr_id);
                    /* WARNING: Load size is inaccurate */
      if ((pzVar1 != (zcl_attr_desc_t *)0x0) && (*pzVar1->data_p == ep_id)) {
        milli_timer_start((uint8_t *)((int)pzVar1->data_p + 4),100);
        return;
      }
      return;
    }
  }
  return;
}

