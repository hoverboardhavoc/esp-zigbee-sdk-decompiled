/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint16_t uVar4;
  byte bVar5;
  ushort uVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  char cVar11;
  int16_t iStack_24;
  int16_t iStack_22;
  int16_t min_val;
  int16_t max_val;
  
  uVar1 = CONCAT22(in_register_0000202a,attr_id);
  iStack_24 = 0;
  iStack_22 = 0;
  if (uVar1 == 0x24) {
                    /* WARNING: Load size is inaccurate */
    uVar6 = *value;
    uVar8 = 0x5a0;
    goto _L0;
  }
  if (0x24 < uVar1) {
    if (uVar1 == 0x39) {
      uVar4 = 0x38;
_L0:
      pzVar2 = thermostat_srv_get_attr_desc(endpoint,uVar4);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (bVar5 = *pzVar2->data_p, bVar5 <= *value))
      goto _L0;
    }
    else {
      if (0x39 < uVar1) {
        if (uVar1 == 0x45) {
                    /* WARNING: Load size is inaccurate */
          bVar5 = 4;
          bVar7 = *value - 1;
        }
        else {
          if (0x45 < uVar1) {
            if (uVar1 == 0x46) goto _L0;
                    /* WARNING: Load size is inaccurate */
            if ((uVar1 == 0x47) && (*value == '\0')) {
              return 0x87;
            }
            goto _L0;
          }
          if (uVar1 == 0x40) {
                    /* WARNING: Load size is inaccurate */
            bVar5 = 3;
            bVar7 = *value - 1;
          }
          else {
            if (1 < (uVar1 - 0x42 & 0xffff)) goto _L0;
                    /* WARNING: Load size is inaccurate */
            bVar5 = 2;
            bVar7 = *value - 1;
          }
        }
_L190:
        if (bVar5 < bVar7) {
          return 0x87;
        }
        goto _L0;
      }
      if (uVar1 == 0x36) {
        uVar4 = 0x35;
        goto _L0;
      }
      if (uVar1 < 0x37) {
        if (uVar1 == 0x34) {
          pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x35);
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x36);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if ((pzVar2 != (zcl_attr_desc_t *)0x0) && (*value < *pzVar2->data_p)) goto _L0;
          iVar10 = 0;
          if (pzVar3 == (zcl_attr_desc_t *)0x0) goto _L0;
_L0:
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (*pzVar3->data_p < *value) {
            return 0x87;
          }
          if (iVar10 != 0) {
            return 0x87;
          }
          goto _L0;
        }
        if (uVar1 != 0x35) {
          if (uVar1 == 0x32) goto _L0;
          goto _L0;
        }
        uVar4 = 0x36;
      }
      else {
        uVar4 = 0x39;
        if (uVar1 == 0x37) {
          pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x38);
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x39);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (*pzVar2->data_p <= *value)) {
            if (pzVar3 != (zcl_attr_desc_t *)0x0) {
              iVar10 = 0;
              goto _L0;
            }
            goto _L0;
          }
_L0:
          iVar10 = 0x87;
          if (pzVar3 == (zcl_attr_desc_t *)0x0) {
            return 0x87;
          }
          goto _L0;
        }
      }
      pzVar2 = thermostat_srv_get_attr_desc(endpoint,uVar4);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (bVar5 = *pzVar2->data_p, *value <= bVar5))
      goto _L0;
    }
_L0:
    *(byte *)value = bVar5;
    goto _L0;
  }
  if (uVar1 < 0x17) {
    if (0x14 < uVar1) {
      pzVar2 = thermostat_srv_get_attr_desc(endpoint,3);
      uVar4 = 4;
_L0:
      pzVar3 = thermostat_srv_get_attr_desc(endpoint,uVar4);
      if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (pzVar3 == (zcl_attr_desc_t *)0x0)) {
_L0:
        iStack_24 = -0x6ab3;
        iStack_22 = 0x7fff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        iStack_24 = *pzVar2->data_p;
                    /* WARNING: Load size is inaccurate */
        iStack_22 = *pzVar3->data_p;
      }
_L0:
                    /* WARNING: Load size is inaccurate */
      if (*value < iStack_24) {
        return 0x87;
      }
      if (iStack_22 < *value) {
        return 0x87;
      }
      goto _L0;
    }
    if (uVar1 == 8) {
      pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x1c);
      if (pzVar2 == (zcl_attr_desc_t *)0x0) {
_L96:
        pzVar2 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
        goto _L0;
      }
                    /* WARNING: Load size is inaccurate */
      if (*pzVar2->data_p == '\0') {
        return 0x87;
      }
      if (*pzVar2->data_p == '\x03') {
        return 0x87;
      }
    }
    else {
      if (8 < uVar1) {
        if (uVar1 == 0x12) {
_L0:
          thermostat_get_heat_setpoint_limit(endpoint,&iStack_24,&iStack_22);
          goto _L0;
        }
        if (uVar1 < 0x13) {
          if (uVar1 == 0x10) {
                    /* WARNING: Load size is inaccurate */
            if (*value < -0x19) {
              bVar5 = 0xe7;
            }
            else {
              bVar5 = 0x19;
              if (*value < '\x1a') goto _L0;
            }
            goto _L0;
          }
          if (uVar1 != 0x11) goto _L0;
        }
        else if (uVar1 != 0x13) goto _L0;
        thermostat_get_cool_setpoint_limit(endpoint,&iStack_24,&iStack_22);
        goto _L0;
      }
      if (uVar1 < 2) goto _L0;
      if (uVar1 != 7) goto _L0;
      pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x1c);
      if (pzVar2 == (zcl_attr_desc_t *)0x0) goto _L96;
_L0:
                    /* WARNING: Load size is inaccurate */
      if ((*pzVar2->data_p & 0xfb) == 0) {
        return 0x87;
      }
    }
                    /* WARNING: Load size is inaccurate */
    uVar6 = (ushort)*value;
    uVar8 = 100;
_L0:
    if (uVar8 < uVar6) {
      return 0x87;
    }
  }
  else if (uVar1 == 0x1c) {
                    /* WARNING: Load size is inaccurate */
    if (9 < *value) {
      return 0x87;
    }
    if (*value == 2) {
      return 0x87;
    }
    pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x1b);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      if (*pzVar2->data_p < 2) {
                    /* WARNING: Load size is inaccurate */
        cVar11 = *value;
joined_r0x00010548:
        if ((byte)(cVar11 - 4U) < 2) {
          return 0x87;
        }
      }
      else if ((byte)(*pzVar2->data_p - 2) < 2) {
                    /* WARNING: Load size is inaccurate */
        cVar11 = *value;
_L0:
        if (cVar11 == '\x03') {
          return 0x87;
        }
        if (cVar11 == '\x06') {
          return 0x87;
        }
      }
    }
  }
  else {
    if (0x1c < uVar1) {
      if (uVar1 == 0x20) {
                    /* WARNING: Load size is inaccurate */
        uVar6 = (ushort)*value;
        uVar8 = 6;
      }
      else {
        if (uVar1 != 0x23) {
                    /* WARNING: Load size is inaccurate */
          if ((uVar1 == 0x1e) && (*value != '\0')) {
            bVar7 = *value - 3;
            bVar5 = 1;
            goto _L190;
          }
          goto _L0;
        }
                    /* WARNING: Load size is inaccurate */
        uVar6 = (ushort)*value;
        uVar8 = 1;
      }
      goto _L0;
    }
    if (uVar1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
      if (0x19 < *value) {
        return 0x87;
      }
    }
    else {
      if (uVar1 < 0x1a) {
        pzVar2 = thermostat_srv_get_attr_desc(endpoint,5);
        uVar4 = 6;
        goto _L0;
      }
      if (uVar1 == 0x1b) {
                    /* WARNING: Load size is inaccurate */
        if (5 < *value) {
          return 0x87;
        }
        pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x1c);
        if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          cVar11 = *pzVar2->data_p;
          if (*value < 2) goto joined_r0x00010548;
          if ((byte)(*value - 2) < 2) goto _L0;
        }
      }
    }
  }
_L0:
  pzVar2 = thermostat_srv_get_attr_desc(endpoint,0x19);
  cVar11 = '\0';
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    cVar11 = *pzVar2->data_p;
  }
  uVar4 = 0x13;
  if (uVar1 == 0x13) {
    uVar9 = 0x14;
_L0:
    pzVar2 = thermostat_srv_get_attr_desc(endpoint,(uint16_t)uVar9);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      return '\0';
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if ((int)*pzVar2->data_p + cVar11 * 10 <= (int)*value) {
      return '\0';
    }
  }
  else {
    if (uVar1 < 0x14) {
      uVar4 = 0x11;
      uVar9 = 0x12;
      if (uVar1 == 0x11) goto _L0;
    }
    else {
      uVar9 = 0x14;
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((uVar1 != uVar9) ||
        (pzVar2 = thermostat_srv_get_attr_desc(endpoint,uVar4), pzVar2 == (zcl_attr_desc_t *)0x0))
       || ((int)*value <= (int)*pzVar2->data_p + cVar11 * -10)) {
      return '\0';
    }
  }
  return 0x87;
}

