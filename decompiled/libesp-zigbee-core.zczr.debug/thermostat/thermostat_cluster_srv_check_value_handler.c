/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  char cVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  uint16_t uVar5;
  char *pcVar6;
  undefined1 uVar7;
  ezb_zcl_status_t eVar8;
  int iVar9;
  int16_t iStack_24;
  int16_t iStack_22;
  int16_t max_val;
  int16_t min_val;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  iStack_22 = 0;
  iStack_24 = 0;
  pcVar6 = (char *)value;
  if (uVar2 == 0x23) {
_L0:
    if ((byte)*pcVar6 < 2) {
      eVar8 = '\0';
    }
    else {
      eVar8 = 0x87;
    }
_L0:
    if (eVar8 != '\0') {
      return eVar8;
    }
  }
  else {
    if (0x23 < uVar2) {
      if (uVar2 == 0x39) {
        pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x38);
        if (pzVar3 == (zcl_attr_desc_t *)0x0) {
          eVar8 = '\0';
        }
        else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (*value < *pzVar3->data_p) {
            *(byte *)value = *pzVar3->data_p;
            eVar8 = '\0';
          }
          else {
            eVar8 = '\0';
          }
        }
      }
      else if (uVar2 < 0x3a) {
        if (uVar2 == 0x35) {
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x36);
          if (pzVar3 == (zcl_attr_desc_t *)0x0) {
            eVar8 = '\0';
          }
          else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if (*pzVar3->data_p < *value) {
              *(byte *)value = *pzVar3->data_p;
              eVar8 = '\0';
            }
            else {
              eVar8 = '\0';
            }
          }
        }
        else if (uVar2 < 0x36) {
          if (uVar2 == 0x32) goto _L0;
          if (uVar2 == 0x34) {
            pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x35);
            pzVar4 = thermostat_srv_get_attr_desc(endpoint,0x36);
            if (pzVar3 == (zcl_attr_desc_t *)0x0) {
              eVar8 = '\0';
            }
            else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
              if (*value < *pzVar3->data_p) {
                eVar8 = 0x87;
              }
              else {
                eVar8 = '\0';
              }
            }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if ((pzVar4 != (zcl_attr_desc_t *)0x0) && (*pzVar4->data_p < *value)) {
              eVar8 = 0x87;
            }
          }
          else if (uVar2 == 0x24) {
                    /* WARNING: Load size is inaccurate */
            if (*value < 0x5a1) {
              eVar8 = '\0';
            }
            else {
              eVar8 = 0x87;
            }
          }
          else {
            eVar8 = '\0';
          }
        }
        else if (uVar2 == 0x37) {
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x38);
          pzVar4 = thermostat_srv_get_attr_desc(endpoint,0x39);
          if (pzVar3 == (zcl_attr_desc_t *)0x0) {
            eVar8 = '\0';
          }
          else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if (*value < *pzVar3->data_p) {
              eVar8 = 0x87;
            }
            else {
              eVar8 = '\0';
            }
          }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if ((pzVar4 != (zcl_attr_desc_t *)0x0) && (*pzVar4->data_p < *value)) {
            eVar8 = 0x87;
          }
        }
        else if (uVar2 == 0x38) {
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x39);
          if (pzVar3 == (zcl_attr_desc_t *)0x0) {
            eVar8 = '\0';
          }
          else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if (*pzVar3->data_p < *value) {
              *(byte *)value = *pzVar3->data_p;
              eVar8 = '\0';
            }
            else {
              eVar8 = '\0';
            }
          }
        }
        else if (uVar2 == 0x36) {
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x35);
          if (pzVar3 == (zcl_attr_desc_t *)0x0) {
            eVar8 = '\0';
          }
          else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if (*value < *pzVar3->data_p) {
              *(byte *)value = *pzVar3->data_p;
              eVar8 = '\0';
            }
            else {
              eVar8 = '\0';
            }
          }
        }
        else {
          eVar8 = '\0';
        }
      }
      else if (uVar2 == 0x45) {
                    /* WARNING: Load size is inaccurate */
        if ((byte)(*value - 1U) < 5) {
          eVar8 = '\0';
        }
        else {
          eVar8 = 0x87;
        }
      }
      else if (uVar2 < 0x46) {
        if (uVar2 == 0x42) {
                    /* WARNING: Load size is inaccurate */
          if ((byte)(*value - 1U) < 3) {
            eVar8 = '\0';
          }
          else {
            eVar8 = 0x87;
          }
        }
        else if (uVar2 == 0x43) {
                    /* WARNING: Load size is inaccurate */
          if ((byte)(*value - 1U) < 3) {
            eVar8 = '\0';
          }
          else {
            eVar8 = 0x87;
          }
        }
        else if (uVar2 == 0x40) {
                    /* WARNING: Load size is inaccurate */
          if ((byte)(*value - 1U) < 4) {
            eVar8 = '\0';
          }
          else {
            eVar8 = 0x87;
          }
        }
        else {
          eVar8 = '\0';
        }
      }
      else {
        if (uVar2 == 0x46) {
          iStack_22 = -0x6ab3;
          iStack_24 = 0x7fff;
          goto _L0;
        }
        if (uVar2 == 0x47) {
                    /* WARNING: Load size is inaccurate */
          if (*value == '\0') {
            eVar8 = 0x87;
          }
          else {
            eVar8 = '\0';
          }
        }
        else {
          eVar8 = '\0';
        }
      }
      goto _L0;
    }
    if (0x16 < uVar2) {
      if (uVar2 == 0x1c) {
                    /* WARNING: Load size is inaccurate */
        if (*value < 10) {
          if (*value == 2) {
            eVar8 = 0x87;
          }
          else {
            pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x1b);
            if (pzVar3 == (zcl_attr_desc_t *)0x0) {
              eVar8 = '\0';
            }
            else {
                    /* WARNING: Load size is inaccurate */
              if (*pzVar3->data_p < 2) {
                    /* WARNING: Load size is inaccurate */
                if ((byte)(*value - 4U) < 2) {
                  eVar8 = 0x87;
                }
                else {
                  eVar8 = '\0';
                }
              }
              else if ((byte)(*pzVar3->data_p - 2) < 2) {
                    /* WARNING: Load size is inaccurate */
                if (*value == '\x03') {
                  eVar8 = 0x87;
                }
                else if (*value == '\x06') {
                  eVar8 = 0x87;
                }
                else {
                  eVar8 = '\0';
                }
              }
              else {
                eVar8 = '\0';
              }
            }
          }
        }
        else {
          eVar8 = 0x87;
        }
      }
      else if (uVar2 < 0x1d) {
        if (uVar2 == 0x19) {
                    /* WARNING: Load size is inaccurate */
          if (*value < 0x1a) {
            eVar8 = '\0';
          }
          else {
            eVar8 = 0x87;
          }
        }
        else if (uVar2 < 0x1a) {
          if ((uVar2 - 0x17 & 0xffff) < 2) {
            pzVar3 = thermostat_srv_get_attr_desc(endpoint,5);
            pzVar4 = thermostat_srv_get_attr_desc(endpoint,6);
            if ((pzVar3 == (zcl_attr_desc_t *)0x0) || (pzVar4 == (zcl_attr_desc_t *)0x0)) {
              iStack_22 = -0x6ab3;
              iStack_24 = 0x7fff;
            }
            else {
                    /* WARNING: Load size is inaccurate */
              iStack_22 = *pzVar3->data_p;
                    /* WARNING: Load size is inaccurate */
              iStack_24 = *pzVar4->data_p;
            }
            goto _L0;
          }
          eVar8 = '\0';
        }
        else if (uVar2 == 0x1b) {
                    /* WARNING: Load size is inaccurate */
          if (*value < 6) {
            pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x1c);
            if (pzVar3 == (zcl_attr_desc_t *)0x0) {
              eVar8 = '\0';
            }
            else {
                    /* WARNING: Load size is inaccurate */
              cVar1 = *pzVar3->data_p;
                    /* WARNING: Load size is inaccurate */
              if (*value < 2) {
                if ((byte)(cVar1 - 4U) < 2) {
                  eVar8 = 0x87;
                }
                else {
                  eVar8 = '\0';
                }
              }
              else if ((byte)(*value - 2) < 2) {
                if (cVar1 == '\x03') {
                  eVar8 = 0x87;
                }
                else if (cVar1 == '\x06') {
                  eVar8 = 0x87;
                }
                else {
                  eVar8 = '\0';
                }
              }
              else {
                eVar8 = '\0';
              }
            }
          }
          else {
            eVar8 = 0x87;
          }
        }
        else {
          eVar8 = '\0';
        }
      }
      else if (uVar2 == 0x1e) {
                    /* WARNING: Load size is inaccurate */
        eVar8 = *value;
        if (eVar8 == '\x03') {
          eVar8 = '\0';
        }
        else if (eVar8 == '\x04') {
          eVar8 = '\0';
        }
        else if (eVar8 != '\0') {
          eVar8 = 0x87;
        }
      }
      else if (uVar2 == 0x20) {
                    /* WARNING: Load size is inaccurate */
        if (*value < 7) {
          eVar8 = '\0';
        }
        else {
          eVar8 = 0x87;
        }
      }
      else {
        eVar8 = '\0';
      }
      goto _L0;
    }
    if (0x14 < uVar2) {
      pzVar3 = thermostat_srv_get_attr_desc(endpoint,3);
      pzVar4 = thermostat_srv_get_attr_desc(endpoint,4);
      if ((pzVar3 == (zcl_attr_desc_t *)0x0) || (pzVar4 == (zcl_attr_desc_t *)0x0)) {
        iStack_22 = -0x6ab3;
        iStack_24 = 0x7fff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        iStack_22 = *pzVar3->data_p;
                    /* WARNING: Load size is inaccurate */
        iStack_24 = *pzVar4->data_p;
      }
      goto _L0;
    }
    if (uVar2 == 8) {
_L0:
      pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x1c);
      if (pzVar3 == (zcl_attr_desc_t *)0x0) {
        pcVar6 = "thermostat_cluster_srv_check_value_handler";
        __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",0x365,"attr_desc");
        goto _L0;
      }
                    /* WARNING: Load size is inaccurate */
      if (*pzVar3->data_p == '\0') {
        eVar8 = 0x87;
      }
      else if (*pzVar3->data_p == '\x03') {
        eVar8 = 0x87;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        if (*value < 0x65) {
          eVar8 = '\0';
        }
        else {
          eVar8 = 0x87;
        }
      }
      goto _L0;
    }
    if (uVar2 < 9) {
      if (uVar2 != 1) {
        if (uVar2 == 7) {
          pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x1c);
          if (pzVar3 == (zcl_attr_desc_t *)0x0) {
            __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",0x358,
                          "thermostat_cluster_srv_check_value_handler","attr_desc");
            goto _L0;
          }
                    /* WARNING: Load size is inaccurate */
          if (*pzVar3->data_p == '\0') {
            eVar8 = 0x87;
          }
          else if (*pzVar3->data_p == '\x04') {
            eVar8 = 0x87;
          }
          else {
                    /* WARNING: Load size is inaccurate */
            if (*value < 0x65) {
              eVar8 = '\0';
            }
            else {
              eVar8 = 0x87;
            }
          }
        }
        else {
          if (uVar2 == 0) {
            iStack_22 = -0x6ab3;
            iStack_24 = 0x7fff;
            goto _L0;
          }
          eVar8 = '\0';
        }
        goto _L0;
      }
      iStack_22 = -0x6ab3;
      iStack_24 = 0x7fff;
    }
    else {
      if (uVar2 != 0x12) {
        if (uVar2 < 0x13) {
          if (uVar2 == 0x10) {
                    /* WARNING: Load size is inaccurate */
            cVar1 = *value;
            if ((cVar1 < -0x19) || ('\x19' < cVar1)) {
              if (cVar1 < '\0') {
                uVar7 = 0xe7;
              }
              else {
                uVar7 = 0x19;
              }
              *(undefined1 *)value = uVar7;
              eVar8 = '\0';
            }
            else {
              eVar8 = '\0';
            }
          }
          else {
            if (uVar2 == 0x11) goto _L0;
            eVar8 = '\0';
          }
        }
        else {
          if (uVar2 == 0x13) {
_L0:
            thermostat_get_cool_setpoint_limit(endpoint,&iStack_22,&iStack_24);
            goto _L0;
          }
          if (uVar2 == 0x14) goto _L0;
          eVar8 = '\0';
        }
        goto _L0;
      }
_L0:
      thermostat_get_heat_setpoint_limit(endpoint,&iStack_22,&iStack_24);
    }
_L0:
                    /* WARNING: Load size is inaccurate */
    if (*value < iStack_22) {
      return 0x87;
    }
    if (iStack_24 < *value) {
      return 0x87;
    }
    eVar8 = '\0';
  }
  pzVar3 = thermostat_srv_get_attr_desc(endpoint,0x19);
  if (pzVar3 == (zcl_attr_desc_t *)0x0) {
    iVar9 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    iVar9 = (int)*pzVar3->data_p;
  }
  if (uVar2 == 0x13) {
_L0:
    if (uVar2 == 0x11) {
      uVar5 = 0x12;
    }
    else {
      uVar5 = 0x14;
    }
    pzVar3 = thermostat_srv_get_attr_desc(endpoint,uVar5);
    if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      if ((int)*value < iVar9 * 10 + (int)*pzVar3->data_p) {
        eVar8 = 0x87;
      }
      else {
        eVar8 = '\0';
      }
    }
  }
  else {
    if (uVar2 < 0x14) {
      if (uVar2 == 0x11) goto _L0;
      if (uVar2 != 0x12) {
        return eVar8;
      }
    }
    else if (uVar2 != 0x14) {
      return eVar8;
    }
    if (uVar2 == 0x12) {
      uVar5 = 0x11;
    }
    else {
      uVar5 = 0x13;
    }
    pzVar3 = thermostat_srv_get_attr_desc(endpoint,uVar5);
    if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      if ((int)*pzVar3->data_p + iVar9 * -10 < (int)*value) {
        eVar8 = 0x87;
      }
      else {
        eVar8 = '\0';
      }
    }
  }
  return eVar8;
}

