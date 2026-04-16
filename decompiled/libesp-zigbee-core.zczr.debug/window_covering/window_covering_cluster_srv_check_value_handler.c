/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> window_covering.o -> window_covering_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
window_covering_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar2 == 7) {
                    /* WARNING: Load size is inaccurate */
    if (*value < '\0') {
      eVar1 = 0x87;
    }
    else {
      eVar1 = '\0';
    }
  }
  else if (uVar2 < 8) {
    if (uVar2 == 3) {
      pzVar3 = window_covering_srv_get_attr_desc(endpoint,0x10);
      pzVar4 = window_covering_srv_get_attr_desc(endpoint,0x11);
      if (pzVar3 == (zcl_attr_desc_t *)0x0) {
        eVar1 = 0x8b;
      }
      else if ((ushort *)pzVar3->data_p == (ushort *)0x0) {
        eVar1 = 0x8b;
      }
      else if (pzVar4 == (zcl_attr_desc_t *)0x0) {
        eVar1 = 0x8b;
      }
      else if ((ushort *)pzVar4->data_p == (ushort *)0x0) {
        eVar1 = 0x8b;
      }
      else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        if (*pzVar3->data_p < *value) {
          eVar1 = 0x87;
        }
        else if (*value < *pzVar4->data_p) {
          eVar1 = 0x87;
        }
        else {
          eVar1 = '\0';
        }
      }
    }
    else if (uVar2 == 4) {
      pzVar3 = window_covering_srv_get_attr_desc(endpoint,0x12);
      pzVar4 = window_covering_srv_get_attr_desc(endpoint,0x13);
      if (pzVar3 == (zcl_attr_desc_t *)0x0) {
        eVar1 = 0x8b;
      }
      else if ((ushort *)pzVar3->data_p == (ushort *)0x0) {
        eVar1 = 0x8b;
      }
      else if (pzVar4 == (zcl_attr_desc_t *)0x0) {
        eVar1 = 0x8b;
      }
      else if ((ushort *)pzVar4->data_p == (ushort *)0x0) {
        eVar1 = 0x8b;
      }
      else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        if (*pzVar3->data_p < *value) {
          eVar1 = 0x87;
        }
        else if (*value < *pzVar4->data_p) {
          eVar1 = 0x87;
        }
        else {
          eVar1 = '\0';
        }
      }
    }
    else if (uVar2 == 0) {
                    /* WARNING: Load size is inaccurate */
      if (*value < 10) {
        eVar1 = '\0';
      }
      else {
        eVar1 = 0x87;
      }
    }
    else {
      eVar1 = '\0';
    }
  }
  else if (uVar2 == 8) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 0x65) {
      eVar1 = '\0';
    }
    else {
      eVar1 = 0x87;
    }
  }
  else if (uVar2 == 9) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 0x65) {
      eVar1 = '\0';
    }
    else {
      eVar1 = 0x87;
    }
  }
  else {
    eVar1 = '\0';
  }
  return eVar1;
}

